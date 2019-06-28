#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 60;
	this->_max_hp = 60;
	this->_ep = 120;
	this->_max_ep = 120;
	this->_lvl = 1;
	this->_range_ad = 60;
	this->_melee_ad = 5;
	this->_armor_dr = 0;
	std::cout << "Thsssss... You didn't see me!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &copy) : ClapTrap(copy)
{
	std::cout << "With brother to end!" << std::endl;
	*this = copy;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &rhs)
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

NinjaTrap::~NinjaTrap()
{
	std::cout << "My life for Imperator!" << std::endl;
}

int		NinjaTrap::ninjaShoebox(FragTrap const &target)
{
	std::cout << _name << " hit in back " << target.getName() << std::endl;
	return 1;
}

int		NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
	std::cout << _name << " push " << target.getName() << std::endl;
	return 1;
}

int NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
	std::cout << _name << " disappear with " << target.getName() << std::endl;
	return 1;
}