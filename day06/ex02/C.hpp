//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#ifndef CPP_POOL_C_HPP
#define CPP_POOL_C_HPP

#include "Base.hpp"

class C : public Base
{
public:
	C(void);
	C(C const &);
	C & operator=(C const &);
	~C(void);
};


#endif //CPP_POOL_C_HPP
