/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:45:00 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 14:19:18 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony( std::string name, std::string color, std::string kingdom) :
	_grandName( name ), _magicColor( color), _humanKingdom( kingdom )
{
	std::cout << _grandName << " - " << _magicColor << " pony is born!";
	std::cout << " The ruler of " << _humanKingdom << "!" << std::endl;
}

Pony::~Pony()
{
	std::cout << "From now " << _grandName << " is Unicorn!" << std::endl;
}

std::string	Pony::getGrandNamePony( void ) const
{
	return this->_grandName;
}

std::string	Pony::getMagicColorPony( void ) const
{
	return this->_magicColor;
}

std::string	Pony::getPoniesKingdom( void ) const
{
	return this->_humanKingdom;
}