#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"


int	main()
{
	FragTrap	bot("Bill");
	ScavTrap	bot2("HealBot");
	NinjaTrap	bot3("Assassin");
	NinjaTrap	bot4(bot3);

	std::cout << std::endl;

	bot3.beRepaired(2);
	bot3.rangedAttack("Bob");
	bot3.meleeAttack("King");
	bot3.takeDamage(100);
	bot3.beRepaired(99);

	std::cout << std::endl;

	bot3.ninjaShoebox(bot);
	bot3.ninjaShoebox(bot2);
	bot3.ninjaShoebox(bot4);

	return 0;
}
