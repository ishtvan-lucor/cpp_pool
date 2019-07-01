#ifndef CPP_POOL_AWEAPON_HPP
#define CPP_POOL_AWEAPON_HPP

#include <iostream>

class AWeapon
{
protected:
	std::string	_name;
	int			_ap_cost;
	int			_damage;

public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &copy);
	AWeapon	&operator=(AWeapon const &target);
	virtual ~AWeapon();

	std::string		getName() const;
	int				getAPCost() const;
	int				getDamage() const;
	virtual void	attack() const = 0;
};


#endif //CPP_POOL_AWEAPON_HPP
