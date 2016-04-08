/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:05 by ggilaber          #+#    #+#             */
//   Updated: 2016/04/08 13:05:58 by ngoguey          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "ftrb/rid.hpp"
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

PageNum RID::getPageNum() const {
	return _pageNum;
}

SlotNum RID::getSlotNum() const {
	return _slotNum;
}

std::string RID::toStr() const {
	return ft::f("RID(%, %)", this->_pageNum, this->_slotNum);
}
