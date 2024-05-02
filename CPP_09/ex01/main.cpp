#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cout << "Error: amount of arguments\n", 1;
	try {
		RPN rpn_class(av[1]);
		rpn_class.run_calc();
	}
	catch (std::exception const& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}
