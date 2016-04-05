/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:26 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/05 10:54:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RID_H
# define RID_H

# include <string>

# include "pf/pf.h"
# include "rm/rm.h"

# define NULLPAGE -1
# define NULLSLOT -1

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
	RID() = delete;                             // Default constructor
//	~RID();                                     // Destructor
	RID(PageNum pageNum,                        // Construct RID from page and
		SlotNum slotNum);                       //   slot number;
	RID(RID const &rhs);                        // Copy constructor
	RID &operator=(RID const &rhs);


	PageNum GetPageNum() const;     // Return page number
	SlotNum GetSlotNum() const;     // Return slot number
	std::string toStr() const;
};

#endif
