// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filescan.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/01 10:30:35 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/06 13:58:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>
#include <functional>
#include <cstring>

#include "rm/rm_filescan.hpp"
#include "rm/rm.h"

using rmfs = RM_FileScan;

/* CONSTRUCTION ************************************************************* */
rmfs::RM_FileScan() : _scanning(false)
{

}

rmfs::~RM_FileScan()
{
	if (_scanning)
		delete [] _ref;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter" // TODO: remove

/* EXPOSED ****************************************************************** */
RC rmfs::OpenScan(const RM_FileHandle &fileHandle, AttrType attrType,
				  int attrLength, int attrOffset, CompOp compOp,
				  void const *value, ClientHint pinHint/*= NO_HINT*/)
{
	decltype(rmfs::comparators.find({})) it;

	if (_scanning)
		return RM_ALREADYSCANNING;
	if ((attrType == INT || attrType == FLOAT) && attrLength != 4)
		return RM_BADSCANARGUMENTS;
	it = rmfs::comparators.find({attrType, compOp});
	if (it == rmfs::comparators.end())
		return RM_BADSCANARGUMENTS;
	_ref = reinterpret_cast<char*>(
		::memcpy(new char[attrLength], reinterpret_cast<char const*>(value),
				 attrLength));
	_comp = it->second;
	_length = attrLength;
	_offset = attrOffset;
	_scanning = true;
	_rmfh = &fileHandle;
	(void)pinHint; //TODO: handle pinHint;
	return 0;
}

RC rmfs::GetNextRec(RM_Record &rec) //TODO
{
	char *_pData;

	_pData = nullptr;
	_comp(_ref, _pData + _offset, _length);
	return 0;
}

RC rmfs::CloseScan(void)
{
	if (!_scanning)
		return RM_NOTSCANNING;
	_scanning = false;
	delete [] _ref;
	return 0;
}

#pragma clang diagnostic pop

/* INTERNAL ***************************************************************** */

// Numbers overload
template <typename T, template<typename> class Comparator>
struct Comparison
{
	static bool of_pointers(void const *lhs, void const *rhs, int) {

		return Comparator<T>{}(
			*reinterpret_cast<T const*>(lhs), *reinterpret_cast<T const*>(rhs));
	}
};

// String overload
template <template<typename> class Comparator>
struct Comparison<char*, Comparator>
{
	static bool of_pointers(void const *lhs, void const *rhs, int length) {

		int const diff = ::strncmp(reinterpret_cast<char const *>(lhs),
								   reinterpret_cast<char const *>(rhs), length);

		return Comparator<char>{}(diff, 0);
	}
};

static bool no_comp(void const *, void const *, int)
{
	return true;
}

rmfs::comp_map_t const rmfs::comparators = /*static*/
{
	{{INT, EQ_OP}, &Comparison<int32_t, std::equal_to>::of_pointers},
	{{INT, LT_OP}, &Comparison<int32_t, std::less>::of_pointers},
	{{INT, GT_OP}, &Comparison<int32_t, std::greater>::of_pointers},
	{{INT, LE_OP}, &Comparison<int32_t, std::less_equal>::of_pointers},
	{{INT, GE_OP}, &Comparison<int32_t, std::greater_equal>::of_pointers},
	{{INT, NE_OP}, &Comparison<int32_t, std::not_equal_to>::of_pointers},
	{{FLOAT, EQ_OP}, &Comparison<float, std::equal_to>::of_pointers},
	{{FLOAT, LT_OP}, &Comparison<float, std::less>::of_pointers},
	{{FLOAT, GT_OP}, &Comparison<float, std::greater>::of_pointers},
	{{FLOAT, LE_OP}, &Comparison<float, std::less_equal>::of_pointers},
	{{FLOAT, GE_OP}, &Comparison<float, std::greater_equal>::of_pointers},
	{{FLOAT, NE_OP}, &Comparison<float, std::not_equal_to>::of_pointers},
	{{STRING, EQ_OP}, &Comparison<char*, std::equal_to>::of_pointers},
	{{STRING, LT_OP}, &Comparison<char*, std::less>::of_pointers},
	{{STRING, GT_OP}, &Comparison<char*, std::greater>::of_pointers},
	{{STRING, LE_OP}, &Comparison<char*, std::less_equal>::of_pointers},
	{{STRING, GE_OP}, &Comparison<char*, std::greater_equal>::of_pointers},
	{{STRING, NE_OP}, &Comparison<char*, std::not_equal_to>::of_pointers},
	{{INT, NO_OP}, &no_comp},
	{{FLOAT, NO_OP}, &no_comp},
	{{STRING, NO_OP}, &no_comp},
};
