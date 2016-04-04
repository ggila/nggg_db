/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:52:40 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/04 13:32:17 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm/rid.hpp"
#include <string>

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
	RID _rid;
	int _rSize;
	char *_pData;

	RC _SetData(char const *&pData);
	RC _SetRid(RID const &rid);
	RC _SetSize(int const rSize);

public:
	RM_Record();                     // Constructor
	~RM_Record();                     // Destructor

	RM_Record(RM_Record const &src) = delete;
	RM_Record(RM_Record &&src) = delete;
	RM_Record &operator=(RM_Record const &rhs) = delete;
	RM_Record &operator=(RM_Record &&rhs) = delete;

	RC GetData(char *&pData) const;
	// Set pData to point to the record's contents
	RC GetRid(RID &rid) const;       // Get the record id
	RC SetRecord(char const *&pData, RID const &rid, int const rSize);

	std::string toStr() const;
};
