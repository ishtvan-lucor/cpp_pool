#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 100;
	this->_max_hp = 100;
	this->_ep = 100;
	this->_max_ep = 100;
	this->_lvl = 1;
	this->_range_ad = 20;
	this->_melee_ad = 30;
	this->_armor_dr = 5;
	std::cout << "Hey everybody! Check out my package!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
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
