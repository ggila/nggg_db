// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   error.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 12:16:16 by ngoguey           #+#    #+#             //
//   Updated: 2016/03/30 14:09:18 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sstream>
#include <iostream>

#include "ftrb/error.hpp"

namespace ftrb // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


// Temporary redirect cerr to oss
std::string errToStr(RC code)
{
	std::ostringstream oss;
	std::streambuf *old;
	std::string str;

	old = std::cerr.rdbuf(oss.rdbuf());
	oss << '"';
	PF_PrintError(code);
	std::cerr.rdbuf(old);
	str = oss.str();
	if (str.length() > 0)
		*str.rbegin() = '"';
	else
		str += '"';
	return str;
}


}; // ~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE FTRB //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
