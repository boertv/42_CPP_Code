#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << '\n';

	std::cout << "a is " << a << '\n';
	std::cout << "or " << a.toInt() << " as integer" << '\n';
	std::cout << "or " << a.toFloat() << " as float" << '\n';
	std::cout << "b is " << b << '\n';
	std::cout << "or " << b.toInt() << " as integer" << '\n';
	std::cout << "or " << b.toFloat() << " as float" << '\n';
	std::cout << "c is " << c << '\n';
	std::cout << "or " << c.toInt() << " as integer" << '\n';
	std::cout << "or " << c.toFloat() << " as float" << '\n';
	std::cout << "d is " << d << '\n';
	std::cout << "or " << d.toInt() << " as integer" << '\n';
	std::cout << "or " << d.toFloat() << " as float" << '\n';
	std::cout << '\n';
}
