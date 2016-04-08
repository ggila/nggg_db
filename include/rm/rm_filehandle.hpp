// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 10:28:50 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 09:38:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_FILEHANDLE_HPP
# define RM_FILEHANDLE_HPP

# include <functional>

# include "pf/pf.h"
# include "rm/rid.hpp"
# include "rm/rm_record.hpp"

class RM_FileHandle
{
private:
	/* ATTRIBUTES ******************* */
	bool _init;
	std::string _fileName;
	PF_FileHandle _pffh;
	RM_Record::Metrics _recMetrics;

public:

	/* CONSTRUCTION ***************** */
	RM_FileHandle();
	~RM_FileHandle();

	RM_FileHandle(RM_FileHandle const &src) = delete;
	RM_FileHandle(RM_FileHandle &&src) = delete;
	RM_FileHandle &operator=(RM_FileHandle const &rhs) = delete;
	RM_FileHandle &operator=(RM_FileHandle &&rhs) = delete;

    /* EXPOSED ********************** */
	// From subject:
	// Get a record
	RC GetRec(const RID &rid, RM_Record &rec) const;

	// From subject:
	// Insert a new record, return record id
	RC InsertRec(const char *pData, RID &rid);

	// From subject:
	// Delete a record
	RC DeleteRec(const RID &rid);

	// From subject:
	// Update a record
	RC UpdateRec(const RM_Record &rec);

	// From subject:
	// Write dirty page(s) to disk
	RC ForcePages(PageNum pageNum = ALL_PAGES) const;

	// NOT From subject:
	RC SetFile(char const *fileName, PF_FileHandle &&rhs);

	// NOT From subject:
	RC CloseFile(std::function<RC (PF_FileHandle&)> const &f);


private:
};

#endif /* ************************************************* RM_FILEHANDLE_HPP */
