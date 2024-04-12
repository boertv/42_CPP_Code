#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap	frag("frag");
	ScavTrap	scav("scav");
	{
		FragTrap clone(frag);
	}
	std::cout << '\n';

	frag.beRepaired(50);
	frag.takeDamage(100);
	frag.attack("the sand");
	frag.highFivesGuys();
	frag.takeDamage(100);
	frag.attack("the sand");
	std::cout << '\n';
}
