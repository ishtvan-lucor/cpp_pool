/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:46:08 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 19:49:17 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _amountOfArmyZombie(N)
{
	this->_army = new Zombie[_amountOfArmyZombie];
	for ( int i = 0; i < this->_amountOfArmyZombie; i++)
		this->_army[i] = Zombie(_randNameZombie(), "ZombieHorde");
}

ZombieHorde::~ZombieHorde( void )
{
	delete [] this->_army;
}

std::string	ZombieHorde::_randNameZombie( void )
{
	std::string	newName;


	for (int i = 0; i < LEN_NAME; i++)
	{
		newName += std::rand() % ('z' - 'a') + 'a';
	}
	newName[0] = toupper(newName[0]);
	return newName;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < this->_amountOfArmyZombie; i++)
		(this->_army[i]).announce();
}