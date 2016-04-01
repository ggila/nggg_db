// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_iterator.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/01 09:21:14 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/01 09:38:46 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_ITERATOR_HPP
# define RM_ITERATOR_HPP

// # include <iostream>
// # include <>

# include "redbase.h" //CompOp, AttrType, ClientHint

# define RM_EOF 0

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

class RM_FileHandle; // TODO: remove later
class RM_Instance; // TODO: remove later

class Iterator
{
private:
	/* ATTRIBUTES ******************* */


public:

	/* CONSTRUCTION ***************** */
	Iterator(RM_FileHandle const &fileHandle, ClientHint pinHint = NO_HINT);
	Iterator(RM_FileHandle const &fileHandle,
			 AttrType attrType, int attrLength, int attrOffset,
			 CompOp compOp, void *value, ClientHint pinHint = NO_HINT);
	~Iterator();

	Iterator() = delete;
	Iterator(Iterator const &src) = delete;
	Iterator(Iterator &&src) = delete;
	Iterator &operator=(Iterator const &rhs) = delete;
	Iterator &operator=(Iterator &&rhs) = delete;

	/* EXPOSED ********************** */
	RM_Instance *operator*(void);
	void operator++(void);
	void operator++(int);

private:
};


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //



#endif /* *************************************************** RM_ITERATOR_HPP */
