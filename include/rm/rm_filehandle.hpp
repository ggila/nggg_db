// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 10:28:50 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 11:33:25 by ngoguey          ###   ########.fr       //
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
	std::pair<RC, RM_Record> getRec(RID const &rid) const;

	// From subject:
	// Insert a new record, return record id
	std::pair<RC, RID> insertRec(char const *pData);

	// From subject:
	// Delete a record
	RC deleteRec(RID const &rid);

	// From subject:
	// Update a record
	RC updateRec(RM_Record const &rec);

	// From subject:
	// Write dirty page(s) to disk
	RC forcePages(PageNum pageNum = ALL_PAGES) const;

	// NOT From subject:
	RC setFile(char const *fileName, PF_FileHandle &&rhs);

	// NOT From subject:
	RC closeFile(std::function<RC (PF_FileHandle&)> const &f);


private:
};

#endif /* ************************************************* RM_FILEHANDLE_HPP */
