//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat hermes("Hermes Conrad", 34);
		ShrubberyCreationForm form("Lilo");
		RobotomyRequestForm form1("Bender");
		PresidentialPardonForm form2("Fry");
		hermes.signForm(form);
		hermes.signForm(form1);
		hermes.signForm(form2);
		hermes.executeForm(form);
		hermes.executeForm(form1);
		hermes.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat nomberOne("Number One", 1);
		ShrubberyCreationForm form("Lilo");
		RobotomyRequestForm form1("Bender");
		PresidentialPardonForm form2("Fry");
		nomberOne.signForm(form);
		nomberOne.signForm(form1);
		nomberOne.signForm(form2);
		nomberOne.executeForm(form);
		nomberOne.executeForm(form1);
		nomberOne.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat vogel("Warden Vogel", 135);
		ShrubberyCreationForm form("Lilo");
		RobotomyRequestForm form1("Bender");
		PresidentialPardonForm form2("Fry");
		vogel.signForm(form);
		vogel.signForm(form2);
		vogel.executeForm(form);
		vogel.executeForm(form1);
		vogel.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
