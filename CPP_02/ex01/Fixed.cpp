#include "Fixed.hpp"
#include <iostream>
#include <cmath>


const int	Fixed::bpoint = 8;

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
