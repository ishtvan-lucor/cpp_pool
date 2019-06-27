/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:44:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 14:24:46 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <string>
#include <iostream>

class Pony
{
private:
	std::string	_grandName;
	std::string	_magicColor;
	std::string	_humanKingdom;

public:
	Pony ( std::string, std::string, std::string );
	~Pony ( void );

	std::string	getGrandNamePony( void ) const;
	std::string	getMagicColorPony( void ) const;
	std::string	getPoniesKingdom ( void ) const;
};


#endif //PONY_HPP
