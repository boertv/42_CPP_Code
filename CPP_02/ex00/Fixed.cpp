#include "Fixed.hpp"
#include <iostream>

const int	Fixed::bpoint = 8;

Fixed::Fixed()
	: _raw_bits(0) {
	std::cout << "Default constructor called\n"; }

Fixed::Fixed(Fixed const& instance)
{
	std::cout << "Copy constructor called\n";
	this->operator=(instance);
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n"; }

Fixed&	Fixed::operator=(Fixed const& instance)
{
	std::cout << "Copy assignment operator called\n";
	this->_raw_bits = instance.getRawBits();
	return *this;
}

/* GETTERS AND SETTERS */
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->_raw_bits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_raw_bits = raw;
}
