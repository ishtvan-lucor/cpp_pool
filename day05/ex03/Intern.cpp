//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern &Intern::operator=(Intern const &target)
{
	if (this == &target)
		return (*this);
	return (*this);
}

Intern::~Intern()
{}

Form* Intern::makeForm(std::string name, std::string target)
{
	if (name == "robotomy request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (name == "presidential pardon")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else if (name == "shrubbery creation")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	std::cout << "Error: Invalid name form!" << std::endl;
	return (NULL);
}
