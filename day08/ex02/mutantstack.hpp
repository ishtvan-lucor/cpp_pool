//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#ifndef CPP_POOL_MUTANTSTACK_HPP
#define CPP_POOL_MUTANTSTACK_HPP

#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>() {}
	MutantStack<T>(MutantStack<T> const& copy): std::stack<T>(copy) {}
	MutantStack<T>	&operator=(MutantStack<T> const &target)
	{
		this->c = target.c;
		return (*this);
	}
	~MutantStack<T>() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void)
	{
		return (this->c.begin());
	}

	iterator end(void)
	{
		return (this->c.end());
	}
};

#endif //CPP_POOL_MUTANTSTACK_HPP
