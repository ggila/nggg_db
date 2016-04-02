/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:05 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/02 15:44:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm/rid.hpp"

RID::RID(PageNum pageNum, SlotNum slotNum)
	: _pageNum(pageNum), _slotNum(slotNum) {}

RID::RID(RID const &rhs)
	: _pageNum(rhs._pageNum), _slotNum(rhs._slotNum) {}

RID &RID::operator=(RID const &rhs)
{
	_pageNum = rhs.GetPageNum();
	_slotNum = rhs.GetSlotNum();

	return (*this);
}

PageNum RID::GetPageNum() const {
	return _pageNum;
}

SlotNum RID::GetSlotNum() const {
	return _slotNum;
}
