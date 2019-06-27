/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:22:51 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 18:07:23 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#define LEN_NAME 5

#include <cstdlib>
#include <cctype>
#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string	_type;

public:
	ZombieEvent( void );
	~ZombieEvent( void );
	void	setZombieType(std::string type);
	Zombie	*newZombie(std::string name);
	void	randomChump( void );
};


#endif //ZOMBIEEVENT_HPP
