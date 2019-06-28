#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _hp(10), _max_hp(10),
										 _ep(10), _max_ep(10), _lvl(1),
										 _name(name), _melee_ad(0),
										 _range_ad(0), _armor_dr(0)
{
	std::cout << "ClapTrap is here!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "More ClapTrap copy!" << std::endl;
	*this = copy;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
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

ClapTrap::~ClapTrap()
{
	std::cout << "The Legion is fall..." << std::endl;
}

void		ClapTrap::setHp(int x)
{
	if (x < 0)
		this->_hp = 0;
	else if (x > this->getMaxHp())
		this->_hp = this->getMaxHp();
	else
		this->_hp = x;
}

void		ClapTrap::setMaxHp(int x)
{
	if (x < 1)
		this->_hp = 1;
	else
		this->_hp = x;
}

void		ClapTrap::setEp(int x)
{
	if (x < 0)
		this->_ep = 0;
	else if (x > this->getMaxEp())
		this->_ep = this->getMaxEp();
	else
		this->_ep = x;
}

void		ClapTrap::setMaxEp(int x)
{
	if (x < 1)
		this->_max_ep = 1;
	else
		this->_max_ep = x;
}

void		ClapTrap::setLvl(int x)
{
	if (x < 1)
		this->_lvl = 1;
	else
		this->_lvl = x;
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void		ClapTrap::setMeleeAd(int x)
{
	if (x < 0)
		this->_melee_ad = 0;
	else
		this->_melee_ad = x;
}

void		ClapTrap::setRangeAd(int x)
{
	if (x < 0)
		this->_range_ad = 0;
	else
		this->_range_ad = x;
}

void		ClapTrap::setArmorDr(int x)
{
	if (x < 0)
		this->_armor_dr = 0;
	else
		this->_armor_dr = x;
}

int			ClapTrap::getHp() const
{
	return this->_hp;
}

int			ClapTrap::getMaxHp() const
{
	return this->_max_hp;
}

int			ClapTrap::getEp() const
{
	return this->_ep;
}

int			ClapTrap::getMaxEp() const
{
	return this->_max_ep;
}

int			ClapTrap::getLvl() const
{
	return this->_lvl;
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

int			ClapTrap::getMeleeAd() const
{
	return this->_melee_ad;
}

int			ClapTrap::getRangeAd() const
{
	return this->_range_ad;
}

int			ClapTrap::getArmor_dr() const
{
	return this->_armor_dr;
}

int ClapTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << _name << " attack bastard " <<
			  target << " at range, causing " << _range_ad <<
			  " points of damage !" << std::endl;
	return 1;
}

int ClapTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << _name << " attack bastard " <<
			  target << " at melee, causing " << _melee_ad <<
			  " points of damage !" << std::endl;
	return 1;
}

int ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << _name;
	if ((int)amount > _armor_dr)
	{
		std::cout << " get " << amount << " point damage! ";
		this->setHp(_hp - amount);
	}
	else
		std::cout << " dodge all damage =) ";
	std::cout << "Revenge is neaaaar!" << std::endl;
	return 1;
}

int ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP " << _name;
	if ( _hp == _max_hp )
	{
		std::cout << " have no defects." << std::endl;
		return 1;
	}
	setHp(_hp + amount);
	std::cout << " was repaired!" << std::endl;
	return 1;
}
