#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( std::string name );
	FragTrap( FragTrap const & copy);
	FragTrap &operator=(FragTrap const &rhs);
	~FragTrap();

	int			vaulthunter_dot_exe(std::string const & target);
 };

#endif //CPP_POOL_FRAGTRAP_HPP
