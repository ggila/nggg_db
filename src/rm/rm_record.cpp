/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/06 09:20:38 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */


#include "rm/rm_record.hpp"
#include "ft/utils.hpp"
#include <string>

// TODO: class should be smaller, save _rSize??

using rmr = RM_Record;

rmr::RM_Record() : _rid(), _rSize(0), _pData(nullptr) {}

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
	if (rid.GetPageNum() < 0 || rid.GetSlotNum() < 0)
		return RM_BADRID;
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

RC rmr::IsSet() const {
	return _pData != nullptr;
}

RC rmr::SetRecord(char const *pData, RID const &rid, int rSize)
{
	int err;

	if ((err = _SetRid(rid)) != 0)
		return err;
	if ((err = _SetSize(rSize)) != 0)
		return err;
	if ((err = _SetData(pData)) != 0)
		return err;
	return 0;
}

std::string rmr::toStr() const {
	if (_pData == nullptr)
		return "RM_Record(not set)";
	return ft::f("RM_Record(%, %, %)", _rid.toStr(), _rSize, _pData);
}
