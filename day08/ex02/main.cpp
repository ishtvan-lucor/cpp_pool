//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#include "mutantstack.hpp"
#include <iostream>

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int> test(mstack);

	MutantStack<int>::iterator it1 = test.begin();
	MutantStack<int>::iterator ite1 = test.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}

	test.push(42);
	std::cout << test.top() << std::endl;

	int	sum = 0;

	std::cout << "Size: " << test.size() << std::endl;

	while (!test.empty())
	{
		sum++;
		test.pop();
	}
	std::cout << "Deleted elements " << sum << std::endl;

	return 0;
}