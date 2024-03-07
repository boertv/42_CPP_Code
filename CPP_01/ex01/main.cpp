#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	int		n;
	Zombie*	horde;

	n = 3;
	std::cout << "creating horde of size " << n << '\n';
	horde = zombieHorde(n, "guy");
	{
		int	i = 0;
		while (i < n)
		{
			horde[i].announce();
			i++;
		}
	}
	delete [] horde;
	std::cout << '\n';

	n = 7;
	std::cout << "creating horde of size " << n << '\n';
	horde = zombieHorde(n, "guy");
	{
		int	i = 0;
		while (i < n)
		{
			horde[i].announce();
			i++;
		}
	}
	delete [] horde;
	std::cout << '\n';
}
