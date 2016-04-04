/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:58:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/04 14:11:14 by ngoguey          ###   ########.fr       */
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
 * RM_Manager::OpenFile
 *   CTOR PF_FileHandle
 *   PF_Manager::OpenFile
 *   RM_FileHandle
 *     MOVEOP PF_FileHandle
*/

/*
 * RM_Manager::CloseFile
 *   RM_FileHandle::CloseFile
 *     PF_Manager::CloseFile (Function ptr and this parameter curryfied)
*/

typedef int SlotNum;

# define RM_RECORDPERPAGE  (START_RM_WARN + 0) // recordSize too big
# define RM_NULLDATA       (START_RM_WARN + 1) // passing null data to rm_rec
# define RM_BADRECSIZE     (START_RM_WARN + 2) // bad record size in rm_rec
# define RM_RECNONINIT     (START_RM_WARN + 3) // rm_rec used initialized

#endif
