#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "please provide one level of urgency\n";
		return 1;
	}

	Harl	harl;
	switch (Harl::gauge(av[1])) {
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		case 0:
			harl.complain(Harl::lvl_arr[0]);
		case 1:
			harl.complain(Harl::lvl_arr[1]);
		case 2:
			harl.complain(Harl::lvl_arr[2]);
		case 3:
			harl.complain(Harl::lvl_arr[3]);
	}
}
