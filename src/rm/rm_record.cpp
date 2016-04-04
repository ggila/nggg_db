/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/04 09:59:54 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */


#include "rm/rm_record.hpp"

using rmr = RM_Record;

rmr::RM_Record() : _rid(-1, -1), _rSize(0), _pData(nullptr) {}

rmr::~RM_Record() {
	if (_pData)
		delete [] _pData;
}

RC rmr::GetData(char *&pData) const {
	pData = _pData;
	return pData == nullptr ? RM_RECNONINIT : 0;
}

RC rmr::GetRid(RID &rid) const {
	rid = _rid;
	return _rid.GetPageNum() == -1 ? RM_RECNONINIT : 0;
}

RC rmr::_SetRid(RID const &rid) {
	_rid = rid;
	return 0;
}

RC rmr::_SetSize(int const rSize)
{
	if (rSize <= 0)
		return RM_BADRECSIZE;
	_rSize = rSize;
	return 0;
}

RC rmr::_SetData(char const *&pData)
{
	if (pData == nullptr)
		return RM_NULLDATA;
	_pData = new char[_rSize];
	memcpy(_pData, pData, _rSize);
	return (0);
}

RC rmr::_SetData(char const *&pData, int const rSize)
{
	int err = 0;

	err = this->_SetSize(rSize);
	if (err)
		return err;
	return (this->_SetData(pData));
}
