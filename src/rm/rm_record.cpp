/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/02 16:42:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rm/rm_record.hpp"

using rmr = RM_Record;


rmr::RM_Record() : _rid(-1, -1) {
	_pData = new char[recordSize];
}

rmr::~RM_Record() {
	delete [] _pData;
}

RC rmr::GetData(char *&pData) const {
	pData = _pData;
	return pData == NULL ? RM_RECNONINIT : 0; 
}

RC GetRid(RID &rid) const {
	pData = _pData;
	return pData == NULL ? RM_RECNONINIT : 0; 
}
