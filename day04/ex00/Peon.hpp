#ifndef PEON_HPP
#define PEON_HPP

#include "iostream"
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(Peon const &copy);
	Peon	&operator=(Peon const &target);
	~Peon();

	std::string		getName( void ) const;
	virtual void	getPolymorphed() const;
};

std::ostream &operator<<(std::ostream & out, Peon const &rhs);

#endif //CPP_POOL_PEON_HPP
