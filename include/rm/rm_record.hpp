/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:52:40 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/01 15:16:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm/rid.hpp"

/*
** The RM_Record class defines record objects. To materialize a record,
** client creates an instance of this class and passes it to one of the
** RM_FileHandle or RM_FileScan methods that reads a record.
** RM_Record objects should contain copies of records from the buffer pool, not
** records in the buffer pool itself.
*/

class RM_Record
{
private:
	/* ATTRIBUTES ******************* */
	char *_pData;
	RID _rid;

public:
	RM_Record();                     // Constructor
	~RM_Record();                     // Destructor

	RC GetData(char *&pData) const;
	// Set pData to point to the record's contents

	RC GetRid(RID &rid) const;       // Get the record id

	RC SetRecord(char const *pageData, RID const &rid, int recordSize);
};
