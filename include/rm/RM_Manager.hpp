// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:50:39 by ngoguey           #+#    #+#             //
/*   Updated: 2016/03/31 16:55:12 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef RM_MANAGER_HPP
# define RM_MANAGER_HPP

// # include <>

# include "pf/pf.h"

class RM_FileHandle; // TODO: remove this line later

class RM_Manager
{
private:
	/* ATTRIBUTES ******************* */
	PF_Manager &_pfm;

public:
	/* CONSTRUCTION ***************** */
	RM_Manager(PF_Manager &pfm);
	~RM_Manager();

	RM_Manager &GetInstance();  // This is a singleton

	RM_Manager() = delete;
	RM_Manager(RM_Manager const &src) = delete;
	RM_Manager(RM_Manager &&src) = delete;
	RM_Manager &operator=(RM_Manager const &rhs) = delete;
	RM_Manager &operator=(RM_Manager &&rhs) = delete;

	/* EXPOSED ********************** */
	// This method should call PF_Manager::CreateFile to create a paged file called fileName. The records in this file will all have size recordSize. This method should initialize the file by storing appropriate information in the header page. Although recordSize will usually be much smaller than the size of a page, you should compare recordSize with PF_PAGE_SIZE and return a nonzero code if recordSize is too large for your RM component to handle.
    RC CreateFile(const char *fileName, int recordSize);

	// This method should destroy the file whose name is fileName by calling PF_Manager::DestroyFile.
	RC DestroyFile(const char *fileName);

	// This method should open the file called fileName by calling PF_Manager::OpenFile. If the method is successful, the fileHandle object should become a "handle" for the open RM component file. The file handle is used to manipulate the records in the file (see the RM_FileHandle class description below). As in the PF component, it should not be an error if a client opens the same RM file more than once, using a different fileHandle object each time. Each call to the OpenFile method should create a new instance of the open file. You may assume if a file has more than one opened instance then each instance of the open file may be read but will not be modified. If a file is modified while opened more than once, you need not guarantee the integrity of the file or the RM component. You may also assume that DestroyFile will never be called on an open file.
	RC OpenFile(const char *fileName, RM_FileHandle &fileHandle);

	// This method should close the open file instance referred to by fileHandle by calling PF_Manager:: CloseFile.
	RC CloseFile(RM_FileHandle &fileHandle);


private:
	/* INTERNAL ********************* */

};

#endif /* **************************************************** RM_MANAGER_HPP */
