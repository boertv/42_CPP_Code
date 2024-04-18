#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "please provide one argument\n", 1);
	ScalarConverter::convert(av[1]);
}

/*
int that is too big will print impossible for EVERYTHING?
 */