/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:22:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 18:27:37 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int	main(void)
{
	Zombie	testZombie("Sam", "testZombie");
	ZombieEvent		blackNightEvent;

	testZombie.announce();

	blackNightEvent.setZombieType("ChoosenZombie");
	Zombie* newZombie = blackNightEvent.newZombie("Zombie5000");
	newZombie->announce();
	delete newZombie;

	blackNightEvent.randomChump();
	return 0;
}
