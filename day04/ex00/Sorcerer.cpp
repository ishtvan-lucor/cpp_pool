#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) :
	_name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &copy)
{
	*this = copy;
	std::cout << "Make illusion of " << _name << std::endl;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &target)
{
	this->_name= target.getName();
	this->_title = target.getTitle();
	return (*this);
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title <<
	", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &rhs)
{
	return (out << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl);
}

std::string Sorcerer::getName() const
{
	return this->_name;
}

std::string Sorcerer::getTitle() const
{
	return this->_title;
}