//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctype.h>
#include <iomanip>
#include <limits.h>
#include <float.h>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ScalarConversion \"value\"" << std::endl;
		return (0);
	}
	double	scalar = atof(argv[1]);

	if (isnan(scalar))
	{
		std::cout << "char: impossible\n"
					 "int: impossible\n"
					 "float: nanf\n"
					 "double: nan" << std::endl;
		return (0);
	}

	std::cout << "char: ";
	if (std::isprint(scalar))
		std::cout << "\'" << static_cast<char>(scalar) << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (scalar < INT_MIN || scalar > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(scalar) << std::endl;

	std::cout << "float: ";
	if (scalar < FLT_MIN || scalar > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(scalar) << "f" << std::endl;

	std::cout << "double: ";
	if (scalar < DBL_MIN || scalar > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::setprecision(1) << static_cast<double>(scalar) << std::endl;

	return (0);
}
