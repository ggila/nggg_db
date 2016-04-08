// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 11:08:20 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 09:41:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ft/assert.hpp"
#include "rm/rm_filehandle.hpp"

using rmfh = RM_FileHandle;

/* CONSTRUCTION ************************************************************* */
rmfh::RM_FileHandle() : _init(), _fileName(), _pffh()
{

}

rmfh::~RM_FileHandle()
{

}

/* EXPOSED ****************************************************************** */

RC rmfh::GetRec(const RID &rid, RM_Record &rec) const
{
	PF_PageHandle pfph;
	int err;
	char *dat;

	if (!_init)
		return RM_FILEHANDLENOINIT;
	err = _pffh.GetThisPage(rid.GetPageNum(), pfph);
	if (err)
		return err;
	err = pfph.GetData(std::ref(dat));
	if (err)
		return err;
	err = rec.SetRecord(dat, rid, _recMetrics.recSize);
	return err;
}

RC rmfh::InsertRec(const char *pData, RID &rid)
{
	int err;
	PageNum pageNum;
	PF_PageHandle pfph;
	char *dst;

	if (!_init)
		return RM_FILEHANDLENOINIT;
	pageNum = rid.GetPageNum();
	err = _pffh.GetThisPage(pageNum, pfph);
	if (err)
		return err;
	err = pfph.GetData(std::ref(dst));
	if (err)
		return err;
	(void)pData;
	// TODO: assert bit is not set
	// TODO: set bit
	// TODO: memcpy record from pData to dst
	err = _pffh.MarkDirty(pageNum);
	return err;
}

RC rmfh::DeleteRec(const RID &rid)
{
	int err;
	PageNum pageNum;
	PF_PageHandle pfph;
	char *dst;

	if (!_init)
		return RM_FILEHANDLENOINIT;
	pageNum = rid.GetPageNum();
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

RC rmfh::UpdateRec(const RM_Record &rec)
{
	int err;
	RID rid;
	PageNum pageNum;
	PF_PageHandle pfph;
	char *dst, *src;

	if (!_init || !rec.IsSet())
		return RM_FILEHANDLENOINIT;
	err = rec.GetRid(rid);
	FTASSERT(err == 0);
	pageNum = rid.GetPageNum();
	err = _pffh.GetThisPage(pageNum, pfph);
	if (err)
		return err;
	err = pfph.GetData(std::ref(dst));
	if (err)
		return err;
	err = rec.GetData(src);
	if (err)
		return err;
	// TODO: memcpy record from src to dst
	// TODO: assert bit is set
	err = _pffh.MarkDirty(pageNum);
	return err;
}

RC rmfh::ForcePages(PageNum pageNum /*= ALL_PAGES*/) const
{
	return _pffh.ForcePages(pageNum);
}

RC rmfh::SetFile(char const *fileName, PF_FileHandle &&rhs)
{
	if (_init)
		return RM_FILEHANDLEALREADYINIT;
	//TODO: Read info from file header such as recordsize
	_recMetrics = RM_Record::Metrics(42);
	_init = true;
	_fileName = fileName;
	_pffh = rhs;
	return 0;
}

RC rmfh::CloseFile(std::function<RC (PF_FileHandle&)> const &f)
{
	if (!_init)
		return RM_FILEHANDLENOINIT;
	return f(_pffh);
}


/* INTERNAL ***************************************************************** */
