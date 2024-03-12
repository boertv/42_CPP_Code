#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	muscle("muscle");
	{
		ScavTrap clone(muscle);
	}
	std::cout << '\n';

	muscle.beRepaired(10);
	muscle.takeDamage(100);
	muscle.attack("the wind");
	muscle.takeDamage(100);
	muscle.attack("the wind");
	muscle.guardGate();
	std::cout << '\n';
}
