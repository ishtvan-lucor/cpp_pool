/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:44:27 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 14:25:15 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap( std::string name, std::string color, std::string kingdom)
{
	Pony	*bigPony = new Pony(name, color, kingdom);
	delete	bigPony;
}

void	ponyOnTheStack( std::string name, std::string color, std::string kingdom)
{
	Pony	littlePony(name, color, kingdom);
}

int		main(void)
{
	ponyOnTheHeap("Sam", "blue", "USA");
	ponyOnTheStack("Lily", "pink", "Makedonia");
	return 0;
}