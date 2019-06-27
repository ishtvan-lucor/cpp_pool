/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:51:56 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 22:33:09 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon( std::string armor );
	~Weapon( void );
	std::string const	&getType();
	void				setType(std::string type);
};


#endif //CPP_POOL_WEAPON_HPP
