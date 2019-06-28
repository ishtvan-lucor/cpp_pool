#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & copy);
	NinjaTrap &operator=(NinjaTrap const &rfs);
	~NinjaTrap();

	int		ninjaShoebox(NinjaTrap const &target);
	int		ninjaShoebox(FragTrap const &target);
	int		ninjaShoebox(ScavTrap const &target);
};


#endif //CPP_POOL_NINJATRAP_HPP
