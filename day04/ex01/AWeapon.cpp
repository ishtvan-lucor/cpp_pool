#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage): _name(name), _ap_cost(apcost), _damage(damage)
{}

AWeapon::AWeapon(AWeapon const &copy)
{
	*this = copy;
}

AWeapon& AWeapon::operator=(AWeapon const &target)
{
	this->_name = target.getName();
	this->_damage = target.getDamage();
	this->_ap_cost = target.getAPCost();
	return (*this);
}

AWeapon::~AWeapon()
{}

void AWeapon::attack() const
{}

std::string	AWeapon::getName() const
{
	return (this->_name);
}

int			AWeapon::getDamage() const
{
	return (this->_damage);
}

int			AWeapon::getAPCost() const
{
	return (this->_ap_cost);
}