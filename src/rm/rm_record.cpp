/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_record.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:50:31 by ggilaber          #+#    #+#             */
/*   Updated: 2016/04/01 13:37:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rm/rm_record.hpp"

using rmr = RM_Record;

rmr::RM_Record()
	: _pData(NULL), _rid(-1, -1)
{}

rmr::~RM_Record()
{
	if (_pData != NULL)
		delete [] _pData;
}

//rmr::SetRecord()
