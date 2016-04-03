/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:58:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/03 08:58:56 by ggilaber         ###   ########.fr       */
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

typedef int SlotNum;

# define RM_RECORDPERPAGE  (START_RM_WARN + 0) // recordSize too big
# define RM_NULLDATA       (START_RM_WARN + 1) // passing null data to rm_rec
# define RM_BADRECSIZE     (START_RM_WARN + 2) // bad record size in rm_rec
# define RM_RECNONINIT     (START_RM_WARN + 3) // rm_rec used initialized

#endif
