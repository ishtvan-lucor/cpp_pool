//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include "B.hpp"

B::B()
{}

B::B(B const &copy)
{
	*this =copy;
}

B& B::operator=(B const &target)
{
	if (this != &target)
	{
		return (*this);
	}
	return (*this);
}

B::~B()
{}