#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &copy) : AWeapon("Plasma Rifle", 5, 21)
{
	*this = copy;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &target)
{
	this->_name = target.getName();
	this->_damage = target.getDamage();
	this->_ap_cost = target.getAPCost();
	return (*this);
}

PlasmaRifle::~PlasmaRifle()
{}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}