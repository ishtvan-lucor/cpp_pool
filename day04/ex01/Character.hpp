#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"


class Character
{
private:
	std::string	_name;
	int			_ap;
	AWeapon		*_weapon;

public:
	Character(std::string const & name);
	Character(Character const &copy);
	Character &operator=(Character const &target);
	~Character();

	void		recoverAP();
	void		equip(AWeapon* weapon);
	void		attack(Enemy* target);
	std::string	getName() const;
	int			getAp() const;
	AWeapon*	getWeapon() const;
};

std::ostream &operator<<(std::ostream &o, Character const &c);

#endif //CPP_POOL_CHARACTER_HPP
