/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/08 11:52:32 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "rm/rm_record.hpp"
#include "ft/utils.hpp"
#include "ft/assert.hpp"
#include <string>

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


using rmr = Record;

rmr::Record() : _rid(), _rSize(0), _pData(nullptr) {}

rmr::~Record() {
	if (_pData != nullptr)
		delete [] _pData;
}

RC rmr::GetData(char *&pData) const {
	pData = reinterpret_cast<char *>(_pData);
	return pData == nullptr ? RECNONINIT : 0;
}

RC rmr::GetRid(RID &rid) const {
	rid = _rid;
	return _rid.GetPageNum() == -1 ? RECNONINIT : 0;
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
	_pData = new long[(_rSize + sizeof(long) - 1) / sizeof(long)];
	memcpy(_pData, pData, _rSize);
	return (0);
}

RC rmr::IsSet() const {
	return _pData != nullptr;
}

RC rmr::SetRecord(char const *pData, RID const &rid, int rSize) //TODO: keep rsize in this?
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
		return "Record(not set)";
	return ft::f("Record(%, %, %)",
				 _rid.toStr(), _rSize, static_cast<void*>(_pData));
}

using rmrm = Record::Metrics;

// Couln'd find a better way to compute recPerPage
rmrm::Metrics(int recSize)
	: recSize(recSize)
{
	FTASSERT(recSize > 0);

	int const recReprBits = recSize * 8 + 1;
	int const pageBits = PF_PAGE_SIZE * 8;
	int const recPerPageNoAlign = pageBits / recReprBits;
	int const headerBytesNoAlign = (recPerPageNoAlign + 8 - 1) / 8;

	if (recPerPageNoAlign * recSize + headerBytesNoAlign > PF_PAGE_SIZE)
		this->recPerPage = recPerPageNoAlign - 1;
	else
		this->recPerPage = recPerPageNoAlign;
	firstRecOffset = PF_PAGE_SIZE - this->recSize * this->recPerPage;
	return ;
}


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
