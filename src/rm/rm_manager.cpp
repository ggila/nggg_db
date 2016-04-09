// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:52:34 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/09 10:07:45 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>
#include <iostream>

#include "ft/assert.hpp"
#include "ftrb/error.hpp"
#include "rm/rm_manager.hpp"
#include "rm/rm_filehandle.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


using rmm = Manager;

/* CONSTRUCTION ************************************************************* */

Manager *rmm::_instance = nullptr; /* static */

rmm::Manager(PF_Manager &pfm)
	: _pfm(pfm)
{
	return ;
}

rmm::~Manager()
{
	return ;
}

Manager &rmm::getInstance(PF_Manager &pfm)
{
	if (rmm::_instance != NULL)
		throw std::runtime_error("RM_Manager instance already initialized");
	rmm::_instance = new Manager(pfm);
	return *rmm::_instance;
}

Manager &rmm::getInstance(void)
{
	if (rmm::_instance == NULL)
		throw std::runtime_error("RM_Manager instance not initialized");
	return *rmm::_instance;
}

/* EXPOSED ****************************************************************** */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove
RC rmm::createFile(const char *fileName, int recordSize)
{

    int err;
	Record::Metrics recMetrics;

	if (recordSize <= 0)
		return RM_BADRECORDSIZE;
	recMetrics =  Record::Metrics(recordSize);
	if (recMetrics.recPerPage < MIN_RECORD_PER_PAGE)
		return RM_BADRECORDSIZE;
	if ((err = _pfm.CreateFile(fileName)) != 0)
		return err;
	err = InitFileHeader{_pfm}(fileName, recordSize);
	return err;

//TODO: Write data to file header
/*
//set PF Header
//   PF_FileHdr *hdr = (PF_FileHdr*)hdrBuf;
hdr->firstFree = PF_PAGE_LIST_END;
hdr->numPages = 1;

// Set RM Header
//   FileHdr *hdr = (FileHdr*)hdrBuf;
hdr->firstFree = PF_PAGE_LIST_END;
hdr->numPages = 1;
*/
	return err;
}
#pragma clang diagnostic pop

RC rmm::destroyFile(const char *fileName)
{
	return _pfm.DestroyFile(fileName);
}

std::pair<RC, FileHandle> rmm::openFile(const char *fileName)
{
	int err;
	PF_FileHandle pffh;
	FileHandle fileHandle;

	err = _pfm.OpenFile(fileName, pffh);
	if (err)
		return {err, FileHandle{}};
	err = fileHandle.setFile(fileName, std::move(pffh));
	if (err)
	{
		(void)_pfm.CloseFile(pffh);
		return {err, FileHandle{}};
	}
	return {0, std::move(fileHandle)};
}

RC rmm::closeFile(FileHandle &fileHandle)
{
	return fileHandle.closeFile(
		std::bind(&PF_Manager::CloseFile, &_pfm, std::placeholders::_1));
}

/* INTERNAL ***************************************************************** */

rmm::InitFileHeader::InitFileHeader(PF_Manager &pfm)
    : ftrb::WaryOperation(), _pfm(pfm), _pffh()
{
	return ;
}


RC rmm::InitFileHeader::operator()(char const *fileName, int recordSize)
{
	RM_FileHdr const fh[1] = {{.recordSize = recordSize,
							   .firstFreeRec = RM_NO_FREE_REC,
							   .numPages = 0}};
	PF_PageHandle pfph;
	int err;
	char *pData;
	PageNum pn;

	err = _pfm.OpenFile(fileName, _pffh);
	if (err)
		return err;
	this->addDestructionOperation([this]{
			int const err = this->_pfm.CloseFile(this->_pffh);
			FTASSERT(err == 0, ftrb::errToStr(err));
		});

	err = _pffh.AllocatePage(pfph);
	if (err)
		return err;
	this->addDestructionOperation([this]{
			int const err = this->_pffh.UnpinPage(0);
			FTASSERT(err == 0, ftrb::errToStr(err));
		});

	FTASSERT((pfph.GetPageNum(pn), pn == 0));
	err = pfph.GetData(pData);
	if (err)
		return err;
	::memcpy(pData, fh, sizeof(RM_FileHdr));
	err = _pffh.MarkDirty(0);
	return err;
}

rmm::InitFileHeader::~InitFileHeader()
{}


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
