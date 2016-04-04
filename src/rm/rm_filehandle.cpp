// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 11:08:20 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/04 14:18:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove
RC rmfh::GetRec(const RID &rid, RM_Record &rec) const
{

	// rec.SetRecord(pData, rid, rSize);
	return 0;
}

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
		return RM_FILEHANDLEALREADYINIT; //TODO: some error code
	_init = true;
	_fileName = fileName;
	_pffh = rhs;
	return 0;
}

RC rmfh::CloseFile(std::function<RC (PF_FileHandle&)> const &f)
{
	if (!_init)
		return RM_FILEHANDLENOINIT; //TODO: some error code
	return f(_pffh);
}


/* INTERNAL ***************************************************************** */