#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & copy);
	ScavTrap &operator=(ScavTrap const &rhs);
	~ScavTrap();

	int			challengeNewcomer( void );
};


#endif //CPP_POOL_SCAVTRAP_HPP
