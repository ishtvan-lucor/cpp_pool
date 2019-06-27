/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:45:04 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 19:02:58 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#define LEN_NAME 6

#include "Zombie.hpp"

class ZombieHorde
{
private:
	int			_amountOfArmyZombie;
	Zombie*		_army;

	std::string	_randNameZombie( void );

public:
	ZombieHorde(int N);
	~ZombieHorde();

	void		announce( void );
};


#endif //ZOMBIEHORDE_HPP
