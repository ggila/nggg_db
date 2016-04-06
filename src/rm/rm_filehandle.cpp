// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 11:08:20 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/06 08:15:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "rm/rm_filehandle.hpp"

using rmfh = RM_FileHandle;

/* CONSTRUCTION ************************************************************* */
rmfh::RM_FileHandle() : _init(), _fileName(), _pffh(), _recordSize()
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
	err = rec.SetRecord(dat, rid, _recordSize);
	return err;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove
RC rmfh::InsertRec(const char *pData, RID &rid)
{
	return 0;
}

RC rmfh::DeleteRec(const RID &rid)
{
	return 0;
}

RC rmfh::UpdateRec(const RM_Record &rec)
{
	return 0;
}

RC rmfh::ForcePages(PageNum pageNum /*= ALL_PAGES*/) const
{
	return 0;
}
#pragma clang diagnostic pop

RC rmfh::SetFile(char const *fileName, PF_FileHandle &&rhs)
{
	if (_init)
		return RM_FILEHANDLEALREADYINIT;
	//TODO: Read info from file header such as recordsize
	_recordSize = 42;
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
