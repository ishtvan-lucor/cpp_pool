
#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
private:
	std::string	_name;
	std::string	_title;

public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & copy);
	Sorcerer	&operator=(Sorcerer const & target);
	~Sorcerer( void );

	std::string	getName( void ) const;
	std::string	getTitle( void ) const;
	void		polymorph(Victim const &victim) const;
};

std::ostream & operator<<(std::ostream & out, Sorcerer const &rhs);

#endif //CPP_POOL_SORCERER_HPP
