// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filescan.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/01 10:30:35 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/01 12:01:14 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>

#include "rm/rm_filescan.hpp"

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

using rmi = rm::FileScan;

/* CONSTRUCTION ************************************************************* */
rmi::FileScan()
{

}

rmi::~FileScan()
{

}

/* EXPOSED ****************************************************************** */
RC rmi::OpenScan(const RM_FileHandle &fileHandle,
				 AttrType attrType, int attrLength, int attrOffset,
				 CompOp compOp, void const *value, ClientHint pinHint)
{

}

RC rmi::GetNextRec(RM_Record &rec)
{

}

RC rmi::CloseScan(void)
{

}

/* INTERNAL ***************************************************************** */

template <typename T, template<typename> class Comparator>
static bool compare(void const *lhs, void const *rhs)
{
	return Comparator<T>{}(
		*reinterpret_cast<T const*>(lhs), *reinterpret_cast<T const*>(rhs));
}

// template <typename T>
// // template <bool (*Fn)(int)>
// static bool compare(void const *lhs, void const *rhs)
// {
// 	// return Comparator<T>{}(
// 	// 	*reinterpret_cast<T const*>(lhs), *reinterpret_cast<T const*>(rhs));
// 	return true;
// }


// int							mai(void)
// {
// 	compare<[](int len){return true;}>("", "");

// 	// bool (*fn)(int) = [](int len){return true;};


// 	return (0);
// }

rmi::comp_map_t const rmi::comparators = /*static*/
{
	{{INT, EQ_OP}, &compare<int32_t, std::equal_to>},
	{{INT, LT_OP}, &compare<int32_t, std::less>},
	{{INT, GT_OP}, &compare<int32_t, std::greater>},
	{{INT, LE_OP}, &compare<int32_t, std::less_equal>},
	{{INT, GE_OP}, &compare<int32_t, std::greater_equal>},
	{{INT, NE_OP}, &compare<int32_t, std::not_equal_to>},
	{{FLOAT, EQ_OP}, &compare<float, std::equal_to>},
	{{FLOAT, LT_OP}, &compare<float, std::less>},
	{{FLOAT, GT_OP}, &compare<float, std::greater>},
	{{FLOAT, LE_OP}, &compare<float, std::less_equal>},
	{{FLOAT, GE_OP}, &compare<float, std::greater_equal>},
	{{FLOAT, NE_OP}, &compare<float, std::not_equal_to>},

};

}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
