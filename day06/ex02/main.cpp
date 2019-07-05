//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class D : public Base
{

};

Base * generate(void)
{
	srand(clock());
	Base	*result;
	int		randomN = rand() % 3;

	switch(randomN)
	{
		case 0:
			result = new A;
			break;
		case 1:
			result = new B;
			break;
		case 2:
			result = new C;
			break;
	}
	return result;
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Noname" << std::endl;
}

void identify_from_reference( Base & p )
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		a = a;
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			B& b = dynamic_cast<B &>(p);
			b = b;
			std::cout << "B" << std::endl;
		}
		catch (const std::bad_cast& e)
		{
			try
			{
				C& c = dynamic_cast<C &>(p);
				c = c;
				std::cout << "C" << std::endl;
			}
			catch (const std::bad_cast& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

int	main()
{
	Base *ptr = generate();

	identify_from_pointer(ptr);

	identify_from_reference(*ptr);

	return 0;
}