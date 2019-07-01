#include "Victim.hpp"

Victim::Victim(std::string name) : __name(name)
{
	std::cout << "Some random victim called " << __name <<
	" just popped !" << std::endl;
}

Victim::Victim(Victim const &copy)
{
	*this = copy;
	std::cout << "Another victim!" << std::endl;
}

Victim& Victim::operator=(Victim const &target)
{
	this->__name = target.getName();
	return *this;
}

Victim::~Victim()
{
	std::cout << "Victim " << __name <<
	" just died for no apparent reason !" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Victim const &rhs)
{
	return (out << "I'm " << rhs.getName() << " and I like otters !" << std::endl);
}

void Victim::getPolymorphed() const
{
	std::cout << this->__name <<
	" has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName() const
{
	return this->__name;
}