// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RM_Manager.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 14:52:34 by ngoguey           #+#    #+#             //
//   Updated: 2016/03/30 15:11:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "rm/RM_Manager.hpp"

using rmm = RM_Manager;

rmm::RM_Manager(PF_Manager &pfm)
	: _pfm(pfm)
{
	return ;
}

rmm::~RM_Manager()
{
	return ;
}

RC rmm::CreateFile(const char *fileName, int recordSize)
{
	int err;

	err = _pfm.CreateFile(fileName);
	return err;
}

RC rmm::DestroyFile(const char *fileName)
{
	return _pfm.DestroyFile(fileName);;
}
