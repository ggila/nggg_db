/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rid.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:27:05 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/01 08:59:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm/rid.h"

using rid = RID;

rid::RID(PageNum pageNum, SlotNum slotNum)
	: _pageNum(pageNum), _slotNum(slotNum) {}

RC rid::GetPageNum(PageNum &pageNum) const
{
	pageNum = &_pageNum;
	return 0;
}

RC rid::GetSlotNum(SlotNum &slotNum) const
{
	slotNum = &_slotNum;
	return 0;
}
