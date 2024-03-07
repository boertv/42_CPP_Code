#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];

	int	i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return horde;
}
