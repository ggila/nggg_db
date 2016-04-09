// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   waryoperation.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/09 10:08:22 by ngoguey           #+#    #+#             //
//   Updated: 2016/04/09 10:18:08 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTRB_WARYOPERATION_HPP
# define FTRB_WARYOPERATION_HPP

# include <forward_list>
# include <functional>

namespace ftrb // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


class WaryOperation
{
private:
	using fn_t = std::function<void (void)>;
	std::forward_list<fn_t> _destruction;

protected:
	WaryOperation(){}
	inline virtual ~WaryOperation() {

		for (fn_t &fn : this->_destruction)
			fn();
		return ;
	}

	inline void addDestructionOperation(fn_t &&f) {

		this->_destruction.push_front(f);
		return ;
	}

	WaryOperation(WaryOperation const &src) = delete;
	WaryOperation(WaryOperation &&src) = delete;
	WaryOperation &operator=(WaryOperation const &rhs) = delete;
	WaryOperation &operator=(WaryOperation &&rhs) = delete;
};


}; // ~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE FTRB //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#endif /* ******************************************** FTRB_WARYOPERATION_HPP */
