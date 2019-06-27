#include "Human.hpp"

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack " << target << std::endl;
}

void Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "Intimidating shout " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	typedef void(Human::*f)(std::string const &);
	std::map <std::string, f> m;
	m.insert(std::make_pair("1", &Human::meleeAttack));
	m.insert(std::make_pair("2", &Human::rangedAttack));
	m.insert(std::make_pair("3", &Human::intimidatingShout));
	f &func = m[action_name];
	(this->*func)(target);
}