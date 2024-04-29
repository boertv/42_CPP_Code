#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return std::cout << "please provide one file\n", 1;
	BitcoinExchange btc_class("data.csv");
	if (btc_class.empty())
		return 1;
	(void)av;
}
