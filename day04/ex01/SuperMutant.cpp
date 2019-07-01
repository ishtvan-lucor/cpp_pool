#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &copy) : Enemy(170, "Super Mutant")
{
	*this = copy;
}

SuperMutant& SuperMutant::operator=(SuperMutant const &target)
{
	this->_hp = target.getHP();
	this->_type = target.getType();
	return (*this);
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

void	SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	Enemy::takeDamage(damage);
}
