#include "Zombie.hpp"
#include <iostream>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie*	guy;

	std::cout << "> calling random chump\n";
	randomChump("Rando");

	std::cout << "> creating new zombie\n";
	guy = newZombie("Friend");
	std::cout << "> announcing new zombie\n";
	guy->announce();
	std::cout << "> deleting new zombie\n";
	delete guy;
}
