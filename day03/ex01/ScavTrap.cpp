#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap( std::string name ) : _hp(100), _max_hp(100),
										 _ep(50), _max_ep(50), _lvl(1),
										 _name(name), _melee_ad(20),
										 _range_ad(15), _armor_dr(3)
{
	std::cout << "ScavTrap is ready!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
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

void		ScavTrap::setHp(int x)
{
	if (x < 0)
		this->_hp = 0;
	else if (x > this->getMaxHp())
		this->_hp = this->getMaxHp();
	else
		this->_hp = x;
}

void		ScavTrap::setMaxHp(int x)
{
	if (x < 1)
		this->_hp = 1;
	else
		this->_hp = x;
}

void		ScavTrap::setEp(int x)
{
	if (x < 0)
		this->_ep = 0;
	else if (x > this->getMaxEp())
		this->_ep = this->getMaxEp();
	else
		this->_ep = x;
}

void		ScavTrap::setMaxEp(int x)
{
	if (x < 1)
		this->_max_ep = 1;
	else
		this->_max_ep = x;
}

void		ScavTrap::setLvl(int x)
{
	if (x < 1)
		this->_lvl = 1;
	else
		this->_lvl = x;
}

void		ScavTrap::setName(std::string name)
{
	this->_name = name;
}

void		ScavTrap::setMeleeAd(int x)
{
	if (x < 0)
		this->_melee_ad = 0;
	else
		this->_melee_ad = x;
}

void		ScavTrap::setRangeAd(int x)
{
	if (x < 0)
		this->_range_ad = 0;
	else
		this->_range_ad = x;
}

void		ScavTrap::setArmorDr(int x)
{
	if (x < 0)
		this->_armor_dr = 0;
	else
		this->_armor_dr = x;
}

int			ScavTrap::getHp() const
{
	return this->_hp;
}

int			ScavTrap::getMaxHp() const
{
	return this->_max_hp;
}

int			ScavTrap::getEp() const
{
	return this->_ep;
}

int			ScavTrap::getMaxEp() const
{
	return this->_max_ep;
}

int			ScavTrap::getLvl() const
{
	return this->_lvl;
}

std::string	ScavTrap::getName() const
{
	return this->_name;
}

int			ScavTrap::getMeleeAd() const
{
	return this->_melee_ad;
}

int			ScavTrap::getRangeAd() const
{
	return this->_range_ad;
}

int			ScavTrap::getArmor_dr() const
{
	return this->_armor_dr;
}

int ScavTrap::rangedAttack(const std::string &target)
{
	std::cout << "ScavTrap " << _name << " chill attack" <<
			  target << " at range, causing " << _range_ad <<
			  " points of damage !" << std::endl;
	return 1;
}

int ScavTrap::meleeAttack(const std::string &target)
{
	std::cout << "ScavTrap" << _name << " attack " <<
			  target << " at melee, causing " << _melee_ad <<
			  " points of damage !" << std::endl;
	return 1;
}

int	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << _name;
	if ((int)amount > _armor_dr)
	{
		std::cout << " get " << amount << " point damage! ";
		this->setHp(_hp - amount);
	}
	else
		std::cout << " dodge all damage =) ";
	std::cout << " Soon be cool event!" << std::endl;
	return 1;
}

int	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << _name;
	if ( _hp == _max_hp )
	{
		std::cout << " have no defects." << std::endl;
		return 1;
	}
	setHp(_hp + amount);
	std::cout << " was repaired!" << std::endl;
	return 1;
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
