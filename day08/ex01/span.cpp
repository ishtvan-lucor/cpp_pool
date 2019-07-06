//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#include "span.hpp"

Span::Span(): _n(0)
{}

Span::Span(unsigned int n): _n(n)
{
	_store.reserve(n);
}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span& Span::operator=(Span const &target)
{
	this->_n = target.getN();
	this->_store = target.getStore();
	return *this;
}

Span::~Span()
{}

unsigned int Span::getN() const
{
	return this->_n;
}

std::vector<int> Span::getStore() const
{
	return this->_store;
}

void Span::addNumber(int element)
{
	if (_store.size() < _n)
		_store.push_back(element);
	else
		throw CantAddNumberException();
}

void Span::addRandomNumbers(unsigned int range)
{
	if (range + _store.size() > _n)
		throw CantAddNumberException();
	else
	{
		srand(clock());
		for (unsigned int i = 0; i < range; i++)
			_store.push_back(rand());
	}
}

int Span::shortestSpan()
{
	if (_store.size() < 2)
		throw NoSpanException();

	std::vector<int>	sortedStore = _store;
	std::vector<int>	result = _store;

	std::sort(sortedStore.begin(), sortedStore.end());
	std::adjacent_difference(sortedStore.begin(), sortedStore.end(), result.begin());
	return (*(std::min_element((result.begin() + 1), result.end())));
}

int Span::longestSpan()
{
	if (_store.size() < 2)
		throw NoSpanException();

	return (*(std::max_element(_store.begin(), _store.end())) -
	*(std::min_element(_store.begin(), _store.end())));
}

Span::CantAddNumberException::CantAddNumberException()
{}

Span::CantAddNumberException::CantAddNumberException(const Span::CantAddNumberException &src) {
	*this = src;
}

Span::CantAddNumberException &Span::CantAddNumberException::operator=(const Span::CantAddNumberException &src) {
	(void)src;
	return (*this);
}

Span::CantAddNumberException::~CantAddNumberException() throw() {

}

const char *Span::CantAddNumberException::what() const throw() {
	return "Error: No free space in array!";
}

Span::NoSpanException::NoSpanException() {

}

Span::NoSpanException::NoSpanException(const Span::NoSpanException &src) {
	*this = src;
}

Span::NoSpanException &Span::NoSpanException::operator=(const Span::NoSpanException &src) {
	(void)src;
	return (*this);
}

Span::NoSpanException::~NoSpanException() throw() {

}

const char *Span::NoSpanException::what() const throw() {
	return "Error: No span!";
}