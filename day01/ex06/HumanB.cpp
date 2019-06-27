/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:52:56 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 22:26:41 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{}

HumanB::~HumanB( void )
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_armor = &weapon;
}

void	HumanB::attack( void )
{
	std::cout << _name << " attacks with his " << _armor->getType() << std::endl;
}