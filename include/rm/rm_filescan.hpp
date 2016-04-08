// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filescan.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/01 10:16:27 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 11:34:21 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_FILESCAN_HPP
# define RM_FILESCAN_HPP

# include <unordered_map>
# include <utility> // pair

# include "redbase.h" //CompOp, AttrType, ClientHint

# define RM_EOF nullptr

class RM_FileHandle; // TODO: remove later
class RM_Record; // TODO: remove later

class RM_FileScan
{
private:
	/* ATTRIBUTES ******************* */
	using comp_fn_t = bool (*)(void const *, void const *, int);

	bool _scanning;
	int _offset;
	int _length;
	comp_fn_t _comp;
	char const *_ref;
	RM_FileHandle const *_rmfh;

public:

	/* CONSTRUCTION ***************** */
	RM_FileScan();
	~RM_FileScan();

	RM_FileScan(RM_FileScan const &src) = delete;
	RM_FileScan(RM_FileScan &&src) = delete;
	RM_FileScan &operator=(RM_FileScan const &rhs) = delete;
	RM_FileScan &operator=(RM_FileScan &&rhs) = delete;

	/* EXPOSED ********************** */
	RC openScan(RM_FileHandle const &fileHandle,
				AttrType attrType, int attrLength, int attrOffset,
				CompOp compOp, void const *value, ClientHint pinHint = NO_HINT);
	std::pair<RC, RM_Record> getNextRec(void);
	RC closeScan(void);

private:
	/* INTERNAL ********************* */
	using comp_key_t = std::pair<AttrType, CompOp>;
	struct HashKey {
		std::size_t operator()(comp_key_t const &k) const {

			return k.first << (sizeof(std::size_t) / 2) + k.second; //TODO: Improve hash function
		}
	};

	using comp_map_t = std::unordered_map<comp_key_t, comp_fn_t, HashKey>;

	static comp_map_t const comparators;

};


#endif /* *************************************************** RM_FILESCAN_HPP */
