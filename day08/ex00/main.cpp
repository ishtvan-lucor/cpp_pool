//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

template <typename T>
void	printElement(T	const &array, typename T::const_iterator i)
{
	if (i == array.end())
		std::cout << "Error: no such element in array!" << std::endl;
	else
		std::cout << "Element " << *i << " is present in array" << std::endl;
}

int	main( void )
{
	std::vector<int>	array;
	std::list<int>		list;

	array.push_back(0);
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(42);

	list.push_back(1);
	list.push_back(31);
	list.push_back(4);
	list.push_back(142);

	printElement(array, easyfind(array, 42));
	printElement(array, easyfind(array, 44));

	printElement(list, easyfind(list, 31));
	printElement(list, easyfind(list, 42));

	return (0);
}