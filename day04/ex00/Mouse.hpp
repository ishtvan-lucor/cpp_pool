#ifndef MOUSE_HPP
#define MOUSE_HPP


#include "iostream"
#include "Victim.hpp"

class Mouse : public Victim
{
public:
	Mouse(std::string name);
	Mouse(Mouse const &copy);
	Mouse	&operator=(Mouse const &target);
	~Mouse();

	std::string		getName( void ) const;
	virtual void	getPolymorphed() const;
};

std::ostream &operator<<(std::ostream & out, Mouse const &rhs);
#endif //CPP_POOL_MOUSE_HPP
