// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rm_filescan.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/01 10:16:27 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/08 11:43:58 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RM_FILESCAN_HPP
# define RM_FILESCAN_HPP

# include <unordered_map>
# include <utility> // pair

# include "redbase.h" //CompOp, AttrType, ClientHint

# define RM_EOF nullptr

namespace rm // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class FileHandle; // TODO: remove later
class Record; // TODO: remove later

class FileScan
{
private:
	/* ATTRIBUTES ******************* */
	using comp_fn_t = bool (*)(void const *, void const *, int);

	bool _scanning;
	int _offset;
	int _length;
	comp_fn_t _comp;
	char const *_ref;
	FileHandle const *_rmfh;

public:

	/* CONSTRUCTION ***************** */
	FileScan();
	~FileScan();

	FileScan(FileScan const &src) = delete;
	FileScan(FileScan &&src) = delete;
	FileScan &operator=(FileScan const &rhs) = delete;
	FileScan &operator=(FileScan &&rhs) = delete;

	/* EXPOSED ********************** */
	RC openScan(FileHandle const &fileHandle,
				AttrType attrType, int attrLength, int attrOffset,
				CompOp compOp, void const *value, ClientHint pinHint = NO_HINT);
	std::pair<RC, Record> getNextRec(void);
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


}; // ~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE RM //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#endif /* *************************************************** RM_FILESCAN_HPP */
