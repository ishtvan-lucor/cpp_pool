#include "FragTrap.hpp"

int	main()
{
	FragTrap robot("BigJim");
	FragTrap t1000(robot);

	robot.rangedAttack("t100");
	t1000.meleeAttack("t10");
	robot.takeDamage(4);
	t1000.takeDamage(9);
	t1000.beRepaired(10);
	robot.beRepaired(1);

	robot.vaulthunter_dot_exe("Baby");
	robot.vaulthunter_dot_exe("Bocal");
	robot.vaulthunter_dot_exe("Humanity");
	robot.vaulthunter_dot_exe("Putin");
	robot.vaulthunter_dot_exe("Monday");

	return 0;
}
