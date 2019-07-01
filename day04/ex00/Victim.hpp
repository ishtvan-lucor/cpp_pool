#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
protected:
	std::string	__name;

public:
	Victim(std::string name);
	Victim(Victim const &copy);
	Victim	&operator=(Victim const &target);
	~Victim();

	std::string		getName( void ) const;
	virtual void	getPolymorphed() const;
};

std::ostream &operator<<(std::ostream & out, Victim const &rhs);

#endif //CPP_POOL_VICTIM_HPP
