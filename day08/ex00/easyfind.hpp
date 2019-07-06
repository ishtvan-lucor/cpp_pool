//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-06.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::const_iterator	easyfind(T const &array, int looking)
{
	typename T::const_iterator	ite = array.end();

	for (typename T::const_iterator it = array.begin(); it != ite; it++)
		if (*it == looking)
			return (it);
	return (ite);
}

#endif //EASYFIND_HPP
