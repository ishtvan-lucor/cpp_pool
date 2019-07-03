//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#ifndef CPP_POOL_INTERN_HPP
#define CPP_POOL_INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
public:
	Intern(void);
	Intern(Intern const &copy);
	Intern	&operator=(Intern const &target);
	~Intern(void);

	Form		*makeForm(std::string name, std::string target);
};

#endif //CPP_POOL_INTERN_HPP
