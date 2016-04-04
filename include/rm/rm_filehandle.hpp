// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 10:28:50 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/04 11:33:11 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_FILEHANDLE_HPP
# define RM_FILEHANDLE_HPP

# include "pf/pf.h"
# include "rm/rid.hpp"
# include "rm/rm_record.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class RM_FileHandle
{
public:

	/* CONSTRUCTION ***************** */
	RM_FileHandle();
	~RM_FileHandle();

	RM_FileHandle(RM_FileHandle const &src) = delete;
	RM_FileHandle(RM_FileHandle &&src) = delete;
	RM_FileHandle &operator=(RM_FileHandle const &rhs) = delete;
	RM_FileHandle &operator=(RM_FileHandle &&rhs) = delete;

    /* EXPOSED ********************** */
	// Get a record
	RC GetRec(const RID &rid, RM_Record &rec) const;

	// Insert a new record, return record id
	RC InsertRec(const char *pData, RID &rid);

	// Delete a record
	RC DeleteRec(const RID &rid);

	// Update a record
	RC UpdateRec(const RM_Record &rec);

	// Write dirty page(s) to disk
	RC ForcePages(PageNum pageNum = ALL_PAGES) const;

private:
};


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

#endif /* ************************************************* RM_FILEHANDLE_HPP */
