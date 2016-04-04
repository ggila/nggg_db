/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:58:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/04 14:19:48 by ngoguey          ###   ########.fr       */
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

/*
 * RM_Manager::CreateFile
 *   TODO
 * *************************************
 * RM_Manager::DestroyFile
 *   PF_Manager::DestroyFile
 * *************************************
 * RM_Manager::OpenFile
 *   CTOR PF_FileHandle
 *   PF_Manager::OpenFile
 *   RM_FileHandle
 *     MOVEOP PF_FileHandle
 * *************************************
 * RM_Manager::CloseFile
 *   RM_FileHandle::CloseFile
 *     PF_Manager::CloseFile ('Function ptr' and 'this'
 *                            parameters previously curryfied)
*/

typedef int SlotNum;

enum e_rm_warning_code {
	RM_RECORDPERPAGE = START_RM_WARN, // recordSize too big
	RM_NULLDATA, // passing null data to rm_rec
	RM_BADRECSIZE, // bad record size in rm_rec
	RM_RECNONINIT, // rm_rec used initialized
	RM_BADRID, // rid with negative value
	RM_FILEHANDLENOINIT, // RM_FileHandle not init
	RM_FILEHANDLEALREADYINIT, // RM_FileHandle init
};

enum e_rm_error_code {
	RM_ = START_RM_ERR // - nbError + 1
}

#endif
