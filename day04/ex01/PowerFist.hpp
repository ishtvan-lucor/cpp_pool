#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const &copy);
	PowerFist &operator=(PowerFist const &target);
	~PowerFist();

	void	attack(void) const;
};


#endif //CPP_POOL_POWERFIST_HPP
