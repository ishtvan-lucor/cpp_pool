//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-05.
//

#include "Array.h"
#include <iostream>

int main()
{
	Array<std::string>	array0(3);
	Array<int>			array1(4);
	Array<double>		array2(1);


	array0[0] = "foo";
	array0[1] = "bar";
	array0[2] = "foobar";
	std::cout << array0.size() << " " << array0[0] << " " << array0[1] << " " << array0[2] << std::endl;

	array1[0] = 42;
	std::cout << array1.size() << " " << array1[0] << " " << array1[1] << " " << array1[2] << " " << array1[3]<< std::endl;

	array2[0] = 0.42;
	std::cout << array2.size() << " " << array2[0] << std::endl;

		try
	{
		std::cout << array0[-1];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		std::cout << array1[8] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		std::cout << array2[100500];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}

	return (0);
}

