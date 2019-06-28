#ifndef CPP_POOL_FIXED_HPP
#define CPP_POOL_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static int const	_fractional_bits = 8;

public:
	Fixed( void );
	Fixed(int const value);
	Fixed(float const value);
	~Fixed( void );
	Fixed( Fixed const & copy );

	Fixed			&operator=(Fixed const & rhs);
	Fixed			operator+(Fixed const & rhs);
	Fixed			operator-(Fixed const & rhs);
	Fixed			operator*(Fixed const & rhs);
	Fixed			operator/(Fixed const & rhs);

	Fixed			&operator++(void);
	Fixed			operator++(int);
	Fixed			&operator--(void);
	Fixed			operator--(int);

	bool			operator>(Fixed const & rhs) const;
	bool			operator<(Fixed const & rhs) const;
	bool			operator>=(Fixed const & rhs) const;
	bool			operator<=(Fixed const & rhs) const;
	bool			operator==(Fixed const & rhs) const;
	bool			operator!=(Fixed const & rhs) const;

	static Fixed			max(Fixed &x, Fixed &y);
	static Fixed const		&max(Fixed const &x, Fixed const &y);
	static Fixed			min(Fixed &x, Fixed &y);
	static Fixed const		&min(Fixed const &x, Fixed const &y);

	int				getRawBits( void ) const;
	void			setRawBits ( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);



#endif //CPP_POOL_FIXED_HPP
