/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:58:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/08 11:37:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RM_H
# define RM_H

# include "redbase.h"

# define MIN_RECORD_PER_PAGE 10

//
// RM_FileHdr: Header structure for files
//
struct RM_FileHdr {
//   int firstFree;     // first free page in the linked list
//   int numPages;      // # of pages in the file
	int recordSize;
	int firstFreeRec;	// first free page in the linked list
};

struct RM_PageHdr {
	int firstFreeRec;	// first free page in the linked list


};

/*
 * RM_Manager::CreateFile()
 * *************************************
 * RM_Manager::DestroyFile()
 *   PF_Manager::DestroyFile()
 * *************************************
 * RM_Manager::OpenFile()
 *   CTOR PF_FileHandle()
 *   PF_Manager::OpenFile()
 *   RM_FileHandle()
 *     MOVEOP PF_FileHandle()
 * *************************************
 * RM_Manager::CloseFile()
 *   RM_FileHandle::CloseFile()
 *     PF_Manager::CloseFile() ('Function ptr' and 'this'
 *                               parameters previously curryfied)
*/

/*
 * RM_FileHandle::GetRec()
 *   RID::GetPageNum()
 *   PF_FileHandle::GetThisPage()
 *   PF_PageHandle::GetData()
 *   RM_Record::SetRecord()
 * *************************************
 * RM_FileHandle::InsertRec()
 *   DONE
 * *************************************
 * RM_FileHandle::DeleteRec()
 *   DONE
 * *************************************
 * RM_FileHandle::UpdateRec()
 *   DONE
 * *************************************
 * RM_FileHandle::ForcePages()
 *   PF_FileHandle::ForcePages()
 */

typedef int SlotNum;

enum e_rm_warning_code {
	RM_BADRECORDSIZE = START_RM_WARN, // recordSize too big or too low
	RM_NULLDATA, // passing null data to rm_rec
	RM_BADRECSIZE, // bad record size in rm_rec
	RM_RECNONINIT, // rm_rec used initialized
	RM_BADRID, // rid with negative value
	RM_FILEHANDLENOINIT, // RM_FileHandle not init
	RM_FILEHANDLEALREADYINIT, // RM_FileHandle init
	RM_ALREADYSCANNING, // RM_FileScan::OpenScan without close
	RM_NOTSCANNING, // RM_FileScan::CloseScan without open
	RM_BADSCANARGUMENTS, // RM_FileScan::OpenScan without close
};

enum e_rm_error_code {
	RM_ = END_RM_ERR //  using END_ for enum incrementation
};

#endif
