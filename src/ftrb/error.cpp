// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   error.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/03/30 12:16:16 by ngoguey           #+#    #+#             //
//   Updated: 2016/03/30 12:27:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cerrno>
#include <unordered_map>

#include "ftrb/error.hpp"
#include "ft/utils.hpp"

static const std::unordered_map<RC, std::string> errors{

	{PF_PAGEPINNED, "page pinned in buffer"},
	{PF_PAGENOTINBUF, "page isn't pinned in buffer"},
	{PF_INVALIDPAGE, "invalid page number"},
	{PF_FILEOPEN, "file is open"},
	{PF_CLOSEDFILE, "file is closed"},
	{PF_PAGEFREE, "page already free"},
	{PF_PAGEUNPINNED, "page already unpinned"},
	{PF_EOF, "end of file"},
	{PF_TOOSMALL, "Resize buffer too small"},
	{PF_LASTWARN, "no memory"},
	{PF_NOBUF, "no buffer space"},
	{PF_INCOMPLETEREAD, "incomplete read from file"},
	{PF_INCOMPLETEWRITE, "incomplete write to file"},
	{PF_HDRREAD, "incomplete read of header"},
	{PF_HDRWRITE, "incomplete write to header"},

};


namespace ftrb // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


std::string errToStr(RC code)
{
	std::unordered_map<RC, std::string>::const_iterator it;

	if (code == PF_UNIX)
		return ft::f("Unix error(\"%\")", strerror(errno));
	it = errors.find(code);
	if (it != errors.end())
		return it->second;
	return ft::f("Unknown error (#%)", code);
}


}; // ~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE FTRB //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
