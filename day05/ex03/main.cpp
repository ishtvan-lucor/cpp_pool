//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	hermes("Hermes Conrad", 34);
		Intern		noname;
		Form		*rrf;
		rrf = noname.makeForm("robotomy request", "Bender");
		hermes.signForm(*rrf);
		hermes.executeForm(*rrf);
		rrf = noname.makeForm("presidential pardon", "Lila");
		hermes.signForm(*rrf);
		hermes.executeForm(*rrf);

		rrf = noname.makeForm("shit", "afhdnsakjd");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}