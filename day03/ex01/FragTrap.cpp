#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap( std::string name ) : _hp(100), _max_hp(100),
	_ep(100), _max_ep(100), _lvl(1), _name(name), _melee_ad(30),
	_range_ad(20), _armor_dr(5)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	std::cout << "More FragTrap...MMMm...!" << std::endl;
	*this = copy;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "Nice job, broooo..." << std::endl;
}

void		FragTrap::setHp(int x)
{
	if (x < 0)
		this->_hp = 0;
	else if (x > this->getMaxHp())
		this->_hp = this->getMaxHp();
	else
		this->_hp = x;
}

void		FragTrap::setMaxHp(int x)
{
	if (x < 1)
		this->_hp = 1;
	else
		this->_hp = x;
}

void		FragTrap::setEp(int x)
{
	if (x < 0)
		this->_ep = 0;
	else if (x > this->getMaxEp())
		this->_ep = this->getMaxEp();
	else
		this->_ep = x;
}

void		FragTrap::setMaxEp(int x)
{
	if (x < 1)
		this->_max_ep = 1;
	else
		this->_max_ep = x;
}

void		FragTrap::setLvl(int x)
{
	if (x < 1)
		this->_lvl = 1;
	else
		this->_lvl = x;
}

void		FragTrap::setName(std::string name)
{
	this->_name = name;
}

void		FragTrap::setMeleeAd(int x)
{
	if (x < 0)
		this->_melee_ad = 0;
	else
		this->_melee_ad = x;
}

void		FragTrap::setRangeAd(int x)
{
	if (x < 0)
		this->_range_ad = 0;
	else
		this->_range_ad = x;
}

void		FragTrap::setArmorDr(int x)
{
	if (x < 0)
		this->_armor_dr = 0;
	else
		this->_armor_dr = x;
}

int			FragTrap::getHp() const
{
	return this->_hp;
}

int			FragTrap::getMaxHp() const
{
	return this->_max_hp;
}

int			FragTrap::getEp() const
{
	return this->_ep;
}

int			FragTrap::getMaxEp() const
{
	return this->_max_ep;
}

int			FragTrap::getLvl() const
{
	return this->_lvl;
}

std::string	FragTrap::getName() const
{
	return this->_name;
}

int			FragTrap::getMeleeAd() const
{
	return this->_melee_ad;
}

int			FragTrap::getRangeAd() const
{
	return this->_range_ad;
}

int			FragTrap::getArmor_dr() const
{
	return this->_armor_dr;
}

int FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << _name << " attack bastard " <<
	target << " at range, causing " << _range_ad <<
	" points of damage !" << std::endl;
	return 1;
}

int FragTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << _name << " attack bastard " <<
			  target << " at melee, causing " << _melee_ad <<
			  " points of damage !" << std::endl;
	return 1;
}

int FragTrap::takeDamage(unsigned int amount)
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

int FragTrap::beRepaired(unsigned int amount)
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

std::string		attacks( void )
{
	std::string		attacks[] = {"Axe", "Banana bomb",
									"Holly bomb", "Projector Peris Hilton",
									"Big Bad Boy from ghetto"};

	srand(clock());
	return (attacks[rand() % 5]);
}

int FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	if (_ep < 25)
	{
		std::cout << "Low charging. Better call Elon Musk." << std::endl;
		return 1;
	}

	setEp(_ep - 25);
	std::cout << "FR4G-TP " << _name << " attack " << target <<
	" by " << attacks() << std::endl;
	return (1);
}
