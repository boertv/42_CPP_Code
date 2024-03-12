#include "Fixed.hpp"
#include <iostream>
#include <cmath>


/*
STATIC ATTRIBUTES AND FUNCTIONS
*/
const int	Fixed::bpoint = 8;

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (b < a)
		return b;
	return a;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (b > a)
		return b;
	return a;
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if (b < a)
		return b;
	return a;
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (b > a)
		return b;
	return a;
}

/*
CONSTRUCTORS, DESTRUCTOR
*/
Fixed::Fixed()
	: _raw_bits(0) {
	std::cout << "Default constructor called\n"; }

Fixed::Fixed(int const i)
	: _raw_bits(i << Fixed::bpoint) {
	std::cout << "Int constructor called\n"; }

Fixed::Fixed(float const f)
	: _raw_bits((int) roundf(f * (1 << Fixed::bpoint))) {
	std::cout << "Float constructor called\n"; }

Fixed::Fixed(Fixed const& instance)
{
	std::cout << "Copy constructor called\n";
	this->operator=(instance);
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n"; }


/*
OPERATOR OVERLOADS
*/
Fixed&	Fixed::operator=(Fixed const& instance)
{
	std::cout << "Copy assignment operator called\n";
	this->_raw_bits = instance.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const& instance) const {
	return this->_raw_bits > instance.getRawBits(); }

bool	Fixed::operator<(Fixed const& instance) const {
	return this->_raw_bits < instance.getRawBits(); }

bool	Fixed::operator>=(Fixed const& instance) const {
	return this->_raw_bits >= instance.getRawBits(); }

bool	Fixed::operator<=(Fixed const& instance) const {
	return this->_raw_bits <= instance.getRawBits(); }

bool	Fixed::operator==(Fixed const& instance) const {
	return this->_raw_bits == instance.getRawBits(); }

bool	Fixed::operator!=(Fixed const& instance) const {
	return this->_raw_bits != instance.getRawBits(); }

Fixed	Fixed::operator+(Fixed const& rhs) const
{
	Fixed	result;
	result.setRawBits(this->_raw_bits + rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	Fixed	result;
	result.setRawBits(this->_raw_bits - rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	Fixed	result;
	result.setRawBits(((long)this->_raw_bits * (long)rhs.getRawBits()) / (1 << Fixed::bpoint));
	return result;
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	Fixed	result;
	result.setRawBits(((long)this->_raw_bits * (1 << Fixed::bpoint) / rhs.getRawBits()));
	return result;
}

Fixed&	Fixed::operator++()
{
	++(this->_raw_bits);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(this->_raw_bits);
	return temp;
}

Fixed&	Fixed::operator--()
{
	--(this->_raw_bits);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(this->_raw_bits);
	return temp;
}

std::ostream&	operator<<(std::ostream& stream, Fixed const& instance) {
	return (stream << instance.toFloat()); }


/*
GETTERS AND SETTERS
*/
int	Fixed::getRawBits() const {
	return this->_raw_bits; }

void	Fixed::setRawBits(int const raw) {
	this->_raw_bits = raw; }


/*
MEMBER FUNCTIONS
*/

float	Fixed::toFloat() const {
	return (float) this->_raw_bits / (1 << Fixed::bpoint); }

int		Fixed::toInt() const {
	return this->_raw_bits >> Fixed::bpoint; }
