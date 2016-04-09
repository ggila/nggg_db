// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 11:08:20 by ngoguey           #+#    #+#             //
/*   Updated: 2016/04/09 11:35:26 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "ft/assert.hpp"
#include "rm/rm_filehandle.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


using rmfh = FileHandle;

/* CONSTRUCTION ************************************************************* */
rmfh::FileHandle()
	: _init(false)
{

}

rmfh::FileHandle(FileHandle &&src)
	: _init(src._init)
	, _fileName(std::move(src._fileName))
	, _pffh(std::move(src._pffh))
{
	src._init = false;
	src._pffh = PF_FileHandle{};
}

rmfh::~FileHandle()
{

}

FileHandle &rmfh::operator=(FileHandle &&rhs)
{
	_init = rhs._init;
	_fileName = std::move(rhs._fileName);
	_pffh = std::move(rhs._pffh);
	_recMetrics = rhs._recMetrics;

	return *this;
}

/* EXPOSED ****************************************************************** */

// RC rmfh::getRec(const RID &rid, Record &rec) const
std::pair<RC, Record> rmfh::getRec(RID const &rid) const
{
	PF_PageHandle pfph;
	int err;
	char *dat;
	Record rec;

	if (!_init)
		return {RM_FILEHANDLENOINIT, Record{}};
	err = _pffh.GetThisPage(rid.getPageNum(), pfph);
	if (err)
		return {err, Record{}};
	err = pfph.GetData(std::ref(dat));
	if (err)
		return {err, Record{}};
	err = rec.setRecord(dat, rid, _recMetrics.recSize);
	return {err, std::move(rec)};
}

// RC rmfh::insertRec(const char *pData, RID &rid)
std::pair<RC, RID> rmfh::insertRec(char const *pData) //TODO
{
	// int err;
	// PageNum pageNum;
	// PF_PageHandle pfph;
	// char *dst;

	// if (!_init)
	// 	return RM_FILEHANDLENOINIT;
	// pageNum = rid.getPageNum();
	// err = _pffh.GetThisPage(pageNum, pfph);
	// if (err)
	// 	return err;
	// err = pfph.GetData(std::ref(dst));
	// if (err)
	// 	return err;
	// (void)pData;
	// // TODO: assert bit is not set
	// // TODO: set bit
	// // TODO: memcpy record from pData to dst
	// err = _pffh.MarkDirty(pageNum);
	// return err;
	return {};
}

RC rmfh::deleteRec(const RID &rid)
{
	int err;
	PageNum pageNum;
	PF_PageHandle pfph;
	char *dst;

	if (!_init)
		return RM_FILEHANDLENOINIT;
	pageNum = rid.getPageNum();
	err = _pffh.GetThisPage(pageNum, pfph);
	if (err)
		return err;
	err = pfph.GetData(std::ref(dst));
	if (err)
		return err;
	// TODO: assert bit is set
	// TODO: set bit
	err = _pffh.MarkDirty(pageNum);
	return err;
}

RC rmfh::updateRec(const Record &rec)
{
	int err;
	RID rid;
	PageNum pageNum;
	PF_PageHandle pfph;
	char *dst, *src;

	if (!_init || !rec.isSet())
		return RM_FILEHANDLENOINIT;
	std::tie(err, rid) = rec.getRid();
	FTASSERT(err == 0);
	pageNum = rid.getPageNum();
	err = _pffh.GetThisPage(pageNum, pfph);
	if (err)
		return err;
	err = pfph.GetData(std::ref(dst));
	if (err)
		return err;
	std::tie(err, src) = rec.getData();
	if (err)
		return err;
	// TODO: memcpy record from src to dst
	// TODO: assert bit is set
	err = _pffh.MarkDirty(pageNum);
	return err;
}

RC rmfh::forcePages(PageNum pageNum /*= ALL_PAGES*/) const
{
	return _pffh.ForcePages(pageNum);
}

RC rmfh::setFile(char const *fileName, PF_FileHandle &&rhs)
{
	if (_init)
		return RM_FILEHANDLEALREADYINIT;
	//TODO: Read info from file header such as recordsize
	_recMetrics = Record::Metrics(42);
	_init = true;
	_fileName = fileName;
	_pffh = rhs;
	return 0;
}

RC rmfh::closeFile(std::function<RC (PF_FileHandle&)> const &f)
{
	if (!_init)
		return RM_FILEHANDLENOINIT;
	return f(_pffh);
}


/* INTERNAL ***************************************************************** */


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
