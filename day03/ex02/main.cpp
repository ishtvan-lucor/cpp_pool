#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	FragTrap	robot("BigJim");
	FragTrap	t1000(robot);
	ScavTrap	baby("Cuty");
	ScavTrap	bot(baby);

	robot.rangedAttack("t100");
	t1000.meleeAttack("t10");
	robot.takeDamage(4);
	t1000.takeDamage(9);
	t1000.beRepaired(10);
	robot.beRepaired(1);

	std::cout << std::endl;
	std::cout << "ScavTrap next" << std::endl;
	std::cout << std::endl;

	baby.rangedAttack("rat");
	baby.meleeAttack("mouse");
	baby.beRepaired(10);
	baby.takeDamage(4);
	baby.takeDamage(1);
	baby.beRepaired(10);
	baby.beRepaired(1);
	std::cout << std::endl;

	robot.vaulthunter_dot_exe("Baby");
	robot.vaulthunter_dot_exe("Bocal");
	robot.vaulthunter_dot_exe("Humanity");
	robot.vaulthunter_dot_exe("Putin");
	robot.vaulthunter_dot_exe("Monday");

	std::cout << std::endl << "Events from Baby%:" << std::endl;
	baby.challengeNewcomer();
	baby.challengeNewcomer();
	baby.challengeNewcomer();
	std::cout << std::endl;


	return 0;
}
