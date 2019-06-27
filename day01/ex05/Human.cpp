/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:06:53 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 21:41:13 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void )
{}

Human::~Human( void )
{}

std::string		Human::identify( void )
{
	return (this->_brainCast.identify());
}

Brain const &	Human::getBrain( void )
{
	return this->_brainCast;
}