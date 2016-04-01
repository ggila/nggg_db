/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:58:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/31 18:45:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RM_H
# define RM_H

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


# define RM_RECORDPERPAGE  (START_RM_WARM + 0) // recordSize too big

#endif