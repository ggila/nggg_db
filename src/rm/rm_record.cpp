/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/01 15:17:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rm/rm_record.hpp"

using rmr = RM_Record;

/*
**  Need those values to works:
**  - recordsize
**  - adresse of file buffer
**
**  TODO: determine whether they should be set as rmr attributes or be passed
**        to rmr methods by caller class.
*/


rmr::RM_Record()
	: _pData(NULL), _rid(-1, -1)
{}

rmr::~RM_Record()
{
	if (_pData != NULL)
		delete [] _pData;
}

RC rmr::SetRecord(char const *pageData, RID const &rid, int recordSize)
{
//	_rid = 
	_pData = new char[recordSize];
	(void)rid;
	(void)pageData;
//	memcpy();
	return 0;
}
