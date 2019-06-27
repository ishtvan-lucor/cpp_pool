/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:23:14 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 18:14:30 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) : _type("defaultZombie") {}

ZombieEvent::~ZombieEvent( void ) {}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie	*freshZombie = new Zombie(name, this->_type);
	return (freshZombie);
}

void	ZombieEvent::randomChump( void )
{
	std::string	newName;


	for (int i = 0; i < LEN_NAME; i++)
	{
		newName += std::rand() % ('z' - 'a') + 'a';
	}
	newName[0] = toupper(newName[0]);

	Zombie	thatStrangeZombie(newName, _type);
	thatStrangeZombie.announce();
}