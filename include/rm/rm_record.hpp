// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_record.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/08 11:44:58 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 13:03:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_RECORD_HPP
# define RM_RECORD_HPP

#include "rm/rid.hpp"
#include <string>

/*
** The RM_Record class defines record objects. To materialize a record,
** client creates an instance of this class and passes it to one of the
** RM_FileHandle or RM_FileScan methods that reads a record.
** RM_Record objects should contain copies of records from the buffer pool, not
** records in the buffer pool itself.
*/

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class Record
{
private:
	/* ATTRIBUTES ******************* */
	RID _rid;
	int _rSize;
	long *_pData;

	RC _setData(char const *&pData);
	RC _setRid(RID const &rid);
	RC _setSize(int const rSize);

public:
	Record();                     // Constructor
	~Record();                     // Destructor
	Record(Record &&src);
	Record &operator=(Record &&rhs);

	Record(Record const &src) = delete;
	Record &operator=(Record const &rhs) = delete;

	// From subject:
	std::pair<RC, char*> getData(void) const;

	// From subject:
	// Get the record id
	std::pair<RC, RID> getRid(void) const;

	// NOT From subject:
	// Set pData to point to the record's contents
	RC setRecord(char const *pData, RID const &rid, int rSize);

	// NOT From subject:
	// return true if instance is set, false otherwise
	RC isSet(void) const;

	// NOT From subject:
	std::string toStr(void) const;

	// NOT From subject:
	struct Metrics
	{
		Metrics(int recSize);

		Metrics() = default;
		~Metrics() = default;
		Metrics(Metrics const &src) = default;
		Metrics(Metrics &&src) = default;
		Metrics &operator=(Metrics const &rhs) = default;
		Metrics &operator=(Metrics &&rhs) = default;

		int recSize;
		int recPerPage;
		int firstRecOffset;
	};
};


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#endif /* ***************************************************** RM_RECORD_HPP */
