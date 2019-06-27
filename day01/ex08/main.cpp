#include "Human.hpp"

int main()
{
	Human warrior;
	std::string command;
	std::string target;
	int n;
	n = -1;
	while (++n < 42)
	{
		std::cout << "Choose attack: 1 - Melee attack; 2 - Ranged attack; 3 - Intimidating shout" << std::endl;
		getline(std::cin, command);
		if (command != "1" && command != "2" && command != "3" )
			break ;
		std::cout << "Enter target name: ";
		getline(std::cin, target);
		warrior.action(command, target);
	}
}