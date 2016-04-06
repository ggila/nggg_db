/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:05 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/06 09:11:18 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "rm/rid.hpp"
#include "ft/utils.hpp"

RID::RID()
	: _pageNum(-1), _slotNum(-1) {}

RID::RID(PageNum pageNum, SlotNum slotNum)
	: _pageNum(pageNum), _slotNum(slotNum) {}

RID::RID(RID const &rhs)
	: _pageNum(rhs._pageNum), _slotNum(rhs._slotNum) {}

RID &RID::operator=(RID const &rhs)
{
	_pageNum = rhs._pageNum;
	_slotNum = rhs._slotNum;

	return (*this);
}

PageNum RID::GetPageNum() const {
	return _pageNum;
}

SlotNum RID::GetSlotNum() const {
	return _slotNum;
}

std::string RID::toStr() const {
	return ft::f("RID(%, %)", this->_pageNum, this->_slotNum);
}
