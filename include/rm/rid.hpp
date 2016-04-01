/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:26 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/01 09:37:17 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef RID_H
# define RID_H

# include "pf/pf.h"
# include "rm/rm.h"

/*
** The RID class defines record identifier objects. A record identifier
** uniquely identifies a record within a given file, based on the record's
** page number in the file and slot number within that page. You may wonder
** why this class name does not begin with RM.
*/

class RID
{
private:
	/* ATTRIBUTES ******************* */
	PageNum _pageNum;
	SlotNum _slotNum;

public:
	/* CONSTRUCTION ***************** */
	RID() = delete;                             // Default constructor
	~RID();                                     // Destructor
	RID(PageNum pageNum,                        // Construct RID from page and
		SlotNum slotNum);                       //   slot number;

	RC GetPageNum (PageNum &pageNum) const;     // Return page number
	RC GetSlotNum (SlotNum &slotNum) const;     // Return slot number
};

#endif