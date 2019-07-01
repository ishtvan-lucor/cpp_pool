#include "Mouse.hpp"

Mouse::Mouse(std::string name) : Victim(name)
{
	std::cout << "Mouse " << __name << " here !" << std::endl;
}

Mouse::Mouse(Mouse const &copy) : Victim(copy.getName())
{
	*this = copy;
}

Mouse& Mouse::operator=(Mouse const &target)
{
	this->__name = target.getName();
	return *this;
}

Mouse::~Mouse()
{
	std::cout << "Mouse now in better world..." << std::endl;
}

std::ostream &operator<<(std::ostream &out, Mouse const &rhs)
{
	return (out << "I'm " << rhs.getName() << " and I like otters but not !" << std::endl);
}

void Mouse::getPolymorphed() const
{
	std::cout << this->__name <<
			  " has been turned into a horse!" << std::endl;
}

std::string Mouse::getName() const
{
	return this->__name;
}