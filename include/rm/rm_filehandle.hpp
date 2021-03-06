// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filehandle.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/04 10:28:50 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/09 14:20:22 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_FILEHANDLE_HPP
# define RM_FILEHANDLE_HPP

# include <functional>

# include "ftrb/waryoperation.hpp"
# include "pf/pf.h"
# include "ftrb/rid.hpp"
# include "rm/rm_record.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class FileHandle
{
private:
	/* ATTRIBUTES ******************* */
	bool _init;
	std::string _fileName;
	PF_FileHandle _pffh;
	Record::Metrics _recMetrics;
	RM_FileHdr _fileHdr;

public:

	/* CONSTRUCTION ***************** */
	FileHandle();
	~FileHandle();
	FileHandle(FileHandle &&src);
	FileHandle &operator=(FileHandle &&rhs);

	FileHandle(FileHandle const &src) = delete;
	FileHandle &operator=(FileHandle const &rhs) = delete;

    /* EXPOSED ********************** */
	// From subject:
	// Get a record
	std::pair<RC, Record> getRec(RID const &rid) const;

	// From subject:
	// Insert a new record, return record id
	std::pair<RC, RID> insertRec(char const *pData);

	// From subject:
	// Delete a record
	RC deleteRec(RID const &rid);

	// From subject:
	// Update a record
	RC updateRec(Record const &rec);

	// From subject:
	// Write dirty page(s) to disk
	RC forcePages(PageNum pageNum = ALL_PAGES) const;

	// NOT From subject:
	RC setFile(char const *fileName, PF_FileHandle &&rhs);

	// NOT From subject:
	RC closeFile(std::function<RC (PF_FileHandle&)> const &f);


private:
	/* INTERNAL ********************* */
	class ReadFileHeader : private ftrb::WaryOperation
	{
	private:
		PF_FileHandle &_pffh;

	public:
		ReadFileHeader(PF_FileHandle &pffh);
		virtual ~ReadFileHeader() final;

		std::pair<RC, RM_FileHdr> operator()(void);

		ReadFileHeader() = delete;
		ReadFileHeader(ReadFileHeader const &src) = delete;
		ReadFileHeader(ReadFileHeader &&src) = delete;
		ReadFileHeader &operator=(ReadFileHeader const &rhs) = delete;
		ReadFileHeader &operator=(ReadFileHeader &&rhs) = delete;
	};

};


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#endif /* ************************************************* RM_FILEHANDLE_HPP */
