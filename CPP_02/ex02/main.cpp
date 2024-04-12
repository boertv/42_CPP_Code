#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed i(25.05f);
	Fixed j(3.25f);
	std::cout << std::endl;

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << b << " (5.05 * 2)" << std::endl;
	std::cout << Fixed::max(a, b) << " (max (a,b))" << std::endl;
	std::cout << std::endl;

	std::cout << (a = a + i) << " (0.0078125 + 25.05)" << std::endl; // 0.0078125 + 25.05
	std::cout << (a / b) << " (25.0586 / 10.1016)" << std::endl; // 25.0586 / 10.1016
	std::cout << (a * j) << " (25.0586 * 3.25)" << std::endl; // 25.0586 * 3.25
	std::cout << std::endl;
	return 0;
}
