/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:52:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 22:20:23 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_armor;

public:
	HumanB(std::string name);
	~HumanB( void );
	void	setWeapon(Weapon& weapon);
	void	attack( void );
};


#endif //CPP_POOL_HUMANB_HPP
