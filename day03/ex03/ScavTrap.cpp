#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 100;
	this->_max_hp = 100;
	this->_ep = 50;
	this->_max_ep = 50;
	this->_lvl = 1;
	this->_range_ad = 15;
	this->_melee_ad = 20;
	this->_armor_dr = 3;
	std::cout << "ScavTrap is ready!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) :ClapTrap(copy)
{
	std::cout << "ScavTrap another one here!" << std::endl;
	*this = copy;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_hp = rhs.getHp();
	this->_max_hp = rhs.getMaxHp();
	this->_ep = rhs.getEp();
	this->_max_ep = rhs.getMaxEp();
	this->_lvl = rhs.getLvl();
	this->_name =rhs.getName();
	this->_melee_ad = rhs.getMeleeAd();
	this->_range_ad = rhs.getRangeAd();
	this->_armor_dr = rhs.getArmor_dr();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap made this day better" << std::endl;
}

int	ScavTrap::challengeNewcomer()
{
	std::string		event[] = {" make you happy)",
						 " want to fight with you but forgot how to do it.",
						 " calling you in gym. The summer is here0",
						 " promise that never eat your meal/",
						 " shoot in you from baby gun)"};

	srand(clock());
	std::cout << "ScavTrap " << _name << event[rand() % 5] << std::endl;
	return 1;
}
