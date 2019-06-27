/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:21:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 18:12:36 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	_name;
	std::string	_type;

public:
	Zombie( void );
	Zombie( std::string name, std::string type );
	~Zombie( void );

	void	announce( void ) const;
};


#endif //ZOMBIE_HPP
