#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return std::cout << "Error: please provide an input file\n", 1;
	try
	{
		BitcoinExchange btc_class("data.csv");
		btc_class.process_file(av[1]);
	}
	catch (std::exception const& e) {
		return std::cout << "Error: " << e.what() << "\n", 1; }
}
