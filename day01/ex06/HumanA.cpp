/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:52:33 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 22:17:20 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &armor) : _name(name), _armor(armor)
{}

HumanA::~HumanA()
{}

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with his " << _armor.getType() << std::endl;
}