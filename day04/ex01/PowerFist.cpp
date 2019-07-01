#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(PowerFist const &copy) :  AWeapon("Power Fist", 8, 50)
{
	*this = copy;
}

PowerFist& PowerFist::operator=(PowerFist const &target)
{
	this->_name = target.getName();
	this->_damage = target.getDamage();
	this->_ap_cost = target.getAPCost();
	return (*this);
}

PowerFist::~PowerFist()
{}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}