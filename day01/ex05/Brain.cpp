/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:06:57 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 21:28:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ): _IQ(0), _EQ(0)
{}

Brain::Brain(int iq, int eq): _IQ(iq), _EQ(eq)
{}

Brain::~Brain( void )
{}

std::string	Brain::identify( void ) const
{
	std::stringstream	way;

	way << this;
	return (way.str());
}

int			Brain::getSumIntelect() const
{
	return (_EQ + _IQ);
}