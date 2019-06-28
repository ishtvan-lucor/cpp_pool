#include "Fixed.hpp"

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fractional_bits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

//
// arithmetic operators
//

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed & Fixed::operator+(Fixed const &rhs)
{
	return (this->_value + rhs.getRawBits());
}

Fixed & Fixed::operator-(Fixed const &rhs)
{
	return (this->_value - rhs.getRawBits());
}

Fixed & Fixed::operator/(Fixed const &rhs)
{
	float res = (float)this->_value / (1 << Fixed::_fractional_bits);

	return (Fixed(res / rhs.toFloat()));
}

Fixed & Fixed::operator*(Fixed const &rhs)
{
	float res = (float)this->_value / (1 << Fixed::_fractional_bits);

	return (Fixed(res * rhs.toFloat()));
}

//
// comparison operators
//

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_value != rhs.getRawBits());
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

//
// ++ --
//

Fixed& Fixed::operator++(void)
{
	this->_fractional_bits++;
	return this;
}

Fixed Fixed::operator++(int)
{
	Fixed buff = *this;

	++(*this);
	return (buff);
}

Fixed& Fixed::operator--(void)
{
	this->_fractional_bits--;
	return this;
}

Fixed Fixed::operator--(int)
{
	Fixed buff = *this;

	--(*this);
	return (buff);
}

//
// min max
//

Fixed	&Fixed::max(Fixed &x, Fixed &y)
{
	return ((x.getRawBits() > y.getRawBits()) ? x : y);
}

Fixed	const &Fixed::max(Fixed const &x, Fixed const &y)
{
	return ((x.getRawBits() > y.getRawBits()) ? x : y);
}

Fixed	&Fixed::min(Fixed &x, Fixed &y)
{
	return ((x.getRawBits() < y.getRawBits()) ? x : y);
}

Fixed	const &Fixed::min(Fixed const &x, Fixed const &y)
{
	return ((x.getRawBits() < y.getRawBits()) ? x : y);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_value / (1 << this->_fractional_bits));
}

int		Fixed::toInt() const
{
	return (this->_value / (1 << this->_fractional_bits));
}


std::ostream & operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return out;
}
