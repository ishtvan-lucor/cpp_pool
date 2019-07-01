#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &copy);
	PlasmaRifle &operator=(PlasmaRifle const &target);
	~PlasmaRifle();

	void	attack(void) const;
};


#endif //CPP_POOL_PLASMARIFLE_HPP
