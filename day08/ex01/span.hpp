//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#ifndef CPP_POOL_SPAN_HPP
#define CPP_POOL_SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <iostream>

class Span
{
private:
	unsigned int		_n;
	std::vector<int>	_store;

public:
	Span( void );
	Span(unsigned int n);
	Span(Span const &copy);
	Span	&operator=(Span const &target);
	~Span();

	unsigned int		getN( void ) const;
	std::vector<int>	getStore( void ) const;
	void				addNumber(int element);
	void				addRandomNumbers(unsigned int range);
	int					shortestSpan( void );
	int					longestSpan( void );

	class CantAddNumberException : public std::exception
	{
	public:
		CantAddNumberException();
		CantAddNumberException(CantAddNumberException const &copy);
		CantAddNumberException &operator=(CantAddNumberException const & target);
		virtual ~CantAddNumberException() throw();
		virtual const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		NoSpanException();
		NoSpanException(NoSpanException const &copy);
		NoSpanException &operator=(NoSpanException const & target);
		 ~NoSpanException() throw();
		virtual const char *what() const throw();
	};
};


#endif //CPP_POOL_SPAN_HPP
