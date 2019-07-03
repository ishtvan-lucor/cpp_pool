//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat hermes("Hermes Conrad", 34);
		Form form343("Registration for suicide box", 42, 21);
		Form form121("Death contract", 5, 1);
		hermes.signForm(form343);
		hermes.signForm(form121);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat monster("Beholder Monster 1.0", 11);
		Form form72("Entrance to hell ", 6, 4);
		Form form729("Entrance to Cubicle Room 729", 15, 11);
		monster.signForm(form72);
		monster.signForm(form729);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form999("Nothing form", 0, 111);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form1001("Nothing from the down form", 42, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}