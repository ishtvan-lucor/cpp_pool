//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat hermes("Hermes Conrad", 34);

		std::cout << hermes << std::endl;
		++hermes;
		std::cout << hermes << std::endl;
		--hermes;
		std::cout << hermes << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat monster("Beholder Monster", 11);

		std::cout << monster << std::endl;
		++(++(++(++(++(++(++(++(++(++(++monster))))))))));
		std::cout << monster << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat numberOne("Number 1.0", 1);

		--numberOne;
		std::cout << numberOne << std::endl;
		++numberOne;
		std::cout << numberOne << std::endl;
		++numberOne;
		std::cout << numberOne << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Try to initialization invalid grade for bureaucrat" << std::endl;

		Bureaucrat vogel("Warden Vogel", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}