/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:06:10 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/26 21:27:03 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <sstream>

class Brain
{
private:
	int	_IQ;
	int	_EQ;

public:
	Brain( void );
	Brain(int, int);
	~Brain();

	std::string	identify( void ) const;
	int			getSumIntelect( void ) const;
};


#endif //CPP_POOL_BRAIN_HPP
