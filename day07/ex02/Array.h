//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-05.
//

#ifndef CPP_POOL_ARRAY_H
#define CPP_POOL_ARRAY_H

#endif //CPP_POOL_ARRAY_H

#include <stdexcept>

template <typename T>
class Array {
private:
	T				*_array;
	unsigned int	_length;

public:
	Array<T>( void ): _array(nullptr), _length(0) {};

	Array<T>(unsigned int value): _array(nullptr), _length(value)
	{
		if (value)
			_array = new T[_length]();
	}

	Array<T>(Array<T> const & copy)
	{
		*this = copy;
	}

	Array<T>	&operator=(Array<T> const &target)
	{
		if (this != &target)
		{
			delete [] (this->_array);
			this->_length = target._length;
			this->_array = new T[this->_length];
			for (unsigned int i = 0; i < this->_length; i++ )
				this->_array[i] = target._array[i];
		}
		return (*this);
	}

	~Array( void )
	{
		delete [] (this->_array);
	}

	unsigned int	size( void )
	{
		return (this->_length);
	}

	T	&operator[](unsigned int index)
	{
		if (index > _length)
			throw std::range_error("Error: wrong index");
		return (_array[index]);
	}
};