/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:06:04 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 21:32:19 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	Brain const	_brainCast;

public:
	Human( void );
	~Human( void );
	std::string		identify( void );
	Brain const &	getBrain( void );
};


#endif //CPP_POOL_HUMAN_HPP
