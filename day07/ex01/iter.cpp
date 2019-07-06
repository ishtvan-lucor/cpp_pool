//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-05.
//

#include <iostream>
#include <string>
0
template <typename T>
void	iter(T *array, unsigned int length, void (*f)(T const &))
{
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	printT(T const & value)
{
	std::cout << value << " ";
}

int	main( void )
{
	int			intArray[] = {0, 1, 0, 42, 21, 990, 101, 110};
	char		charArray[] = {'A', 'B', 'C'};
	std::string	strArray[] = {"foo", "bar", "foobar"};
	double		doubleArray[] = {4.2, 0.42, 0.0042};

	std::cout << "Int array: ";
	::iter(intArray, 8, printT);
	std::cout << std::endl;

	std::cout << "Char array: ";
	::iter(charArray, 3, printT);
	std::cout << std::endl;

	std::cout << "String array: ";
	::iter(strArray, 3, printT);
	std::cout << std::endl;

	std::cout << "Double array: ";
	::iter(doubleArray, 3, printT);
	std::cout << std::endl;

	return (0);
}