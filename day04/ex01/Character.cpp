#include "Character.hpp"

Character::Character(const std::string &name): _name(name), _ap(40), _weapon(NULL)
{}

Character::Character(Character const &copy)
{
	*this = copy;
}

Character& Character::operator=(Character const &target)
{
	this->_name = target.getName();
	this->_ap = target.getAp();
	this->_weapon = target.getWeapon();
	return (*this);
}

Character::~Character()
{}

void Character::recoverAP()
{
	if (this->_ap > 30)
		this->_ap = 40;
	else
		this->_ap += 10;
}
void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void Character::attack(Enemy *target)
{

	if (!(this->_weapon) || this->_ap < (this->_weapon)->getAPCost() ||
		target->getHP() < 0)
		return;

	this->_ap -= (this->_weapon)->getAPCost();
	target->takeDamage(this->_weapon->getDamage());

	std::cout << this->getName() << " attacks " <<
	target->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	if (target->getHP() <= 0)
	{
		std::cout << target->getType() << "was killed." << std::endl;
		delete target;
	}
}

std::string Character::getName() const
{
	return this->_name;
}

AWeapon* Character::getWeapon() const
{
	return this->_weapon;
}

int Character::getAp() const
{
	return this->_ap;
}

std::ostream &operator<<(std::ostream &out, Character const &target)
{
	if (!target.getWeapon())
		return (out << target.getName() << " has " << target.getAp() << " and is unarmed" << std::endl);
	return (out << target.getName() << " has " << target.getAp() <<
	" AP and wields a " << target.getWeapon()->getName() << std::endl);
}