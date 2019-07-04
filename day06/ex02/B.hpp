//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#ifndef CPP_POOL_B_HPP
#define CPP_POOL_B_HPP

#include "Base.hpp"

class B : public Base
{
public:
	B(void);
	B(B const &);
	B & operator=(B const &);
	~B(void);
};


#endif //CPP_POOL_B_HPP
