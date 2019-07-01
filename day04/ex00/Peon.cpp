#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &copy) : Victim(copy.getName())
{
	*this = copy;
}

Peon& Peon::operator=(Peon const &target)
{
	this->__name = target.getName();
	return *this;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

std::ostream &operator<<(std::ostream &out, Peon const &rhs)
{
	return (out << "I'm " << rhs.getName() << " and I like otters !" << std::endl);
}

void Peon::getPolymorphed() const
{
	std::cout << this->__name <<
			  " has been turned into a pink pony !" << std::endl;
}

std::string Peon::getName() const
{
	return this->__name;
}