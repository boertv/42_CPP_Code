#include "PmergeMe.hpp"

static char* prep_number(char* str)
{
	while (*str == '0')
		++str;
	return str;
}

static bool is_digits(std::string str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

static bool is_underflow(std::string str)
{
	if (str.size() < 10)
		return true;
	if (str.size() > 10)
		return false;
	return str <= "2147483647";
}

static bool convert_input(int ac, char** av, int* input)
{
	char* nbr;
	for (int i = 1; i < ac; ++i)
	{
		nbr = prep_number(av[i]);
		if (!is_digits(nbr) || !is_underflow(nbr))
			return std::cout << "Error: bad input '" + std::string(av[i]) + "'\n", false;
		input[i - 1] = std::atoi(nbr);
	}
	return true;
}

int main(int ac, char** av)
{
	if (ac < 3)
		return std::cout << "Error: not enough arguments\n", 1;

	int input[ac - 1];
	if (!convert_input(ac, av, input))
		return 1;
	PmergeMe my_class(input, ac - 1);
	PmergeMe::print_container(my_class.vector, "before:");
//test
std::vector<int> comparison(my_class.vector);
	my_class.sort_vector();
	PmergeMe::print_container(my_class.vector, "after:");
//test
std::sort(comparison.begin(), comparison.end());
if (my_class.vector != comparison)
std::cout << "!!!!! THE SORT DON'T WORK !!!!!\n";
	// my_class.do_vector();
}
