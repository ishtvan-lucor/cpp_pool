/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:52:00 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 22:35:45 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string armor ): _type(armor)
{}

Weapon::~Weapon( void )
{}

std::string const	&Weapon::getType( void )
{
	return _type;
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}