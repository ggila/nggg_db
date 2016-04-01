// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:52:34 by ngoguey           #+#    #+#             //
/*   Updated: 2016/04/01 09:19:43 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <stdexcept>

#include "rm/rm_manager.hpp"

using rmm = RM_Manager;

/* CONSTRUCTION ************************************************************* */

RM_Manager *rmm::_instance = nullptr; /* static */

rmm::RM_Manager(PF_Manager &pfm)
	: _pfm(pfm)
{
	return ;
}

rmm::~RM_Manager()
{
	return ;
}

RM_Manager &rmm::GetInstance(PF_Manager &pfm)
{
	if (rmm::_instance != NULL)
		throw std::runtime_error("RM_Manager instance already initialized");
	rmm::_instance = new RM_Manager(pfm);
	return *rmm::_instance;
}

RM_Manager &rmm::GetInstance(void)
{
	if (rmm::_instance == NULL)
		throw std::runtime_error("RM_Manager instance not initialized");
	return *rmm::_instance;
}

/* EXPOSED ****************************************************************** */

RC rmm::CreateFile(const char *fileName, int recordSize)
{
	int err;
/*
	// check recordSize
	if (recordSize > PF_PAGE_SIZE / MIN_RECORD_PER_PAGE)
		return RN_RECORDPERPAGE;
*/
	// open file with PF_Manager
	if ((err = _pfm.CreateFile(fileName)) != 0)
		return err;
/*
	//set PF Header
//   PF_FileHdr *hdr = (PF_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;

	// Set RM Header
//   RM_FileHdr *hdr = (RM_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;
*/
	return err;
}

RC rmm::DestroyFile(const char *fileName)
{
	return _pfm.DestroyFile(fileName);;
}

/* INTERNAL ***************************************************************** */
