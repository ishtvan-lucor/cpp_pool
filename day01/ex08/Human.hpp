#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <map>

class Human
{
private:
	void meleeAttack(std::string const & target);
	void rangedAttack(std::string const & target);
	void intimidatingShout(std::string const & target);

public:
	void action(std::string const & action_name, std::string const & target);
};


#endif //CPP_POOL_HUMAN_HPP
