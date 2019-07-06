//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#include "span.hpp"
#include <iostream>

int	main()
{
	Span sp = Span(5);
	Span sp1 = Span(10000);


	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp1.addRandomNumbers(10000);
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}
