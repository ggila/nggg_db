// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 11:08:20 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/04 11:40:07 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "rm/rm_filehandle.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove

using rmfh = RM_FileHandle;

/* CONSTRUCTION ************************************************************* */
rmfh::RM_FileHandle()
{

}

rmfh::~RM_FileHandle()
{

}

/* EXPOSED ****************************************************************** */
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

/* INTERNAL ***************************************************************** */

#pragma clang diagnostic pop

}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
