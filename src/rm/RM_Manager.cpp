// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:52:34 by ngoguey           #+#    #+#             //
/*   Updated: 2016/03/31 19:02:14 by ggilaber         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "rm/RM_Manager.hpp"

using rmm = RM_Manager;

rmm::RM_Manager(PF_Manager &pfm)
	: _pfm(pfm)
{
	return ;
}

rmm::~RM_Manager()
{
	return ;
}

nmm::GetInstance()
{
	static RM_Manager instance;

	return instance;
}

RC rmm::CreateFile(const char *fileName, int recordSize)
{
	int err;

	// check recordSize
	if (recordSize > PF_PAGE_SIZE / MIN_RECORD_PER_PAGE)
		return RN_RECORDPERPAGE;

	// open file with PF_Manager
	if ((err = _pfm.CreateFile(fileName)) != 0)
		return err;

	//set PF Header
//   PF_FileHdr *hdr = (PF_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;

	// Set RM Header
//   RM_FileHdr *hdr = (RM_FileHdr*)hdrBuf;
   hdr->firstFree = PF_PAGE_LIST_END;
   hdr->numPages = 1;

}

RC rmm::DestroyFile(const char *fileName)
{
	return _pfm.DestroyFile(fileName);;
}
