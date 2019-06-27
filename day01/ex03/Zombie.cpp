/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:21:39 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 19:46:14 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{}

Zombie::~Zombie()
{}

void	Zombie::announce( void ) const
{
	std::cout << "<" << _name << " (" << _type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}
