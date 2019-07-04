//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include "A.hpp"

A::A()
{}

A::A(A const &copy)
{
	*this =copy;
}

A& A::operator=(A const &target)
{
	if (this != &target)
	{
		return (*this);
	}
	return (*this);
}

A::~A()
{}