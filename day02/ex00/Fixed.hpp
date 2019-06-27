#ifndef CPP_POOL_FIXED_HPP
#define CPP_POOL_FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static int const	_fractional_bits = 8;

public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const & copy );

	Fixed &operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits ( int const raw );
};


#endif //CPP_POOL_FIXED_HPP
