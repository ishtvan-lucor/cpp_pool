//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include "C.hpp"

C::C()
{}

C::C(C const &copy)
{
	*this =copy;
}

C& C::operator=(C const &target)
{
	if (this != &target)
	{
		return (*this);
	}
	return (*this);
}

C::~C()
{}