/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:26 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/08 12:43:33 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef RID_H
# define RID_H

# include <string>

# include "pf/pf.h"
# include "rm/rm.h"

/*
** The RID class defines record identifier objects. A record identifier
** uniquely identifies a record within a given file, based on the record's
** page number in the file and slot number within that page.
*/

class RID
{
private:
	/* ATTRIBUTES ******************* */
	PageNum _pageNum;
	SlotNum _slotNum;

public:
	/* CONSTRUCTION ***************** */
	RID();                             // Default constructor
	~RID();                                     // Destructor
	RID(PageNum pageNum,                        // Construct RID from page and
		SlotNum slotNum);                       //   slot number;
	RID(RID const &rhs);                        // Copy constructor
	RID &operator=(RID const &rhs);

	PageNum getPageNum() const;     // Return page number
	SlotNum getSlotNum() const;     // Return slot number
	std::string toStr() const;
};

#endif
