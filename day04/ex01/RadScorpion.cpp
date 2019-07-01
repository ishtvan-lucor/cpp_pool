#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &copy) : Enemy(80, "RadScorpion")
{
	*this = copy;
}

RadScorpion& RadScorpion::operator=(RadScorpion const &target)
{
	this->_hp = target.getHP();
	this->_type = target.getType();
	return (*this);
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}


