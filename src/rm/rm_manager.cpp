// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:52:34 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 09:46:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>

#include "rm/rm_manager.hpp"
#include "rm/rm_filehandle.hpp"

using rmm = RM_Manager;

/* CONSTRUCTION ************************************************************* */

RM_Manager *rmm::_instance = nullptr; /* static */

rmm::RM_Manager(PF_Manager &pfm)
	: _pfm(pfm)
{
	return ;
}

rmm::~RM_Manager()
{
	return ;
}

RM_Manager &rmm::GetInstance(PF_Manager &pfm)
{
	if (rmm::_instance != NULL)
		throw std::runtime_error("RM_Manager instance already initialized");
	rmm::_instance = new RM_Manager(pfm);
	return *rmm::_instance;
}

RM_Manager &rmm::GetInstance(void)
{
	if (rmm::_instance == NULL)
		throw std::runtime_error("RM_Manager instance not initialized");
	return *rmm::_instance;
}

/* EXPOSED ****************************************************************** */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove
RC rmm::CreateFile(const char *fileName, int recordSize)
{
	int err;
	RM_Record::Metrics recMetrics;

	if (recordSize <= 0)
		return RM_BADRECORDSIZE;
	recMetrics =  RM_Record::Metrics(recordSize);
	if (recMetrics.recPerPage < MIN_RECORD_PER_PAGE)
		return RM_BADRECORDSIZE;
	if ((err = _pfm.CreateFile(fileName)) != 0)
		return err;


//TODO: Write data to file header
/*
	//set PF Header
//   PF_FileHdr *hdr = (PF_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;

	// Set RM Header
//   RM_FileHdr *hdr = (RM_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;
*/
	return err;
}
#pragma clang diagnostic pop

RC rmm::DestroyFile(const char *fileName)
{
	return _pfm.DestroyFile(fileName);
}

RC rmm::OpenFile(const char *fileName, RM_FileHandle &fileHandle)
{
	int err;
	PF_FileHandle pffh;

	err = _pfm.OpenFile(fileName, pffh);
	if (err)
		return err;
	err = fileHandle.SetFile(fileName, std::move(pffh));
	if (err)
	{
		(void)_pfm.CloseFile(pffh);
		return err;
	}
	return 0;
}

RC rmm::CloseFile(RM_FileHandle &fileHandle)
{
	return fileHandle.CloseFile(
		std::bind(&PF_Manager::CloseFile, &_pfm, std::placeholders::_1));
}

/* INTERNAL ***************************************************************** */
