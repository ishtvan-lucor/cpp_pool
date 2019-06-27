/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:56:59 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 20:00:39 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
	std::string		text = "HI THIS IS BRAIN";
	std::string*	ptrText = &text;
	std::string&	refText = text;

	std::cout << "Text display using pointer: " << *ptrText << std::endl;
	std::cout << "Text display using reference: " << refText << std::endl;
	return 1;
}