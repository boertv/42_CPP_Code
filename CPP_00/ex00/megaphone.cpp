#include <iostream>

static void	str_to_upper(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	int i = 0;
	while (++i < ac)
	{
		str_to_upper(av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
}
