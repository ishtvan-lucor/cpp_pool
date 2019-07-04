//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#ifndef CPP_POOL_A_HPP
#define CPP_POOL_A_HPP

#include "Base.hpp"

class A : public Base
{
public:
	A(void);
	A(A const &);
	A & operator=(A const &);
	~A(void);
};


#endif //CPP_POOL_A_HPP
