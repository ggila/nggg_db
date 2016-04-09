// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:50:39 by ngoguey           #+#    #+#             //
/*   Updated: 2016/04/09 11:27:03 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef RM_MANAGER_HPP
# define RM_MANAGER_HPP

# include <utility>

# include "ftrb/waryoperation.hpp"
# include "pf/pf.h"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class FileHandle; // TODO: remove this line later

class Manager
{
private:
	/* ATTRIBUTES ******************* */
	PF_Manager &_pfm;

private:
	/* CONSTRUCTION ***************** */
	static Manager *_instance;
	Manager(PF_Manager &pfm);
	~Manager();

public:
	static Manager &getInstance(PF_Manager &pfm);
	static Manager &getInstance(void);

	Manager() = delete;
	Manager(Manager const &src) = delete;
	Manager(Manager &&src) = delete;
	Manager &operator=(Manager const &rhs) = delete;
	Manager &operator=(Manager &&rhs) = delete;

	/* EXPOSED ********************** */
	/** This method should call PF_Manager::CreateFile to create a paged file
	 ** called fileName. The records in this file will all have size recordSize.
	 ** This method should initialize the file by storing appropriate informa-
	 ** tion in the header page. Although recordSize will usually be much sma-
	 ** ller than the size of a page, you should compare recordSize with
	 ** PF_PAGE_SIZE and return a nonzero code if recordSize is too large for
	 ** your RM component to handle.
	 **/
    RC createFile(const char *fileName, int recordSize);

	/**
	 ** This method should destroy the file whose name is fileName by calling
	 ** PF_Manager::DestroyFile.
	 **/
	RC destroyFile(const char *fileName);

	/** This method should open the file called fileName by calling
	 ** PF_Manager::OpenFile. If the method is successful, the fileHandle object
	 ** should become a "handle" for the open RM component file. The file handle
	 ** is used to manipulate the records in the file (see the RM_FileHandle
	 ** class description below). As in the PF component, it should not be an
	 ** error if a client opens the same RM file more than once, using a diffe-
	 ** rent fileHandle object each time. Each call to the OpenFile method
	 ** should create a new instance of the open file. You may assume if a file
	 ** has more than one opened instance then each instance of the open file
	 ** may be read but will not be modified. If a file is modified while opened
	 ** more than once, you need not guarantee the integrity of the file or the
	 ** RM component. You may also assume that DestroyFile will never be called
	 ** on an open file.
	 **/
	std::pair<RC, FileHandle> openFile(const char *fileName);

	/** This method should close the open file instance referred to by
	 ** fileHandle by calling PF_Manager:: CloseFile.
	 **/
	RC closeFile(FileHandle &fileHandle);

private:
	/* INTERNAL ********************* */
	class InitFileHeader : private ftrb::WaryOperation
	{
	private:
		PF_Manager &_pfm;
		PF_FileHandle _pffh;

	public:
		InitFileHeader(PF_Manager &rmm);
		virtual ~InitFileHeader() final;

		RC operator()(char const *fileName, int recordSize);

		InitFileHeader() = delete;
		InitFileHeader(InitFileHeader const &src) = delete;
		InitFileHeader(InitFileHeader &&src) = delete;
		InitFileHeader &operator=(InitFileHeader const &rhs) = delete;
		InitFileHeader &operator=(InitFileHeader &&rhs) = delete;
	};

};


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#endif /* **************************************************** RM_MANAGER_HPP */
