#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	{
		DiamondTrap	diamond;
	}
	std::cout << '\n';

	{
		DiamondTrap	rough("rough");
		std::cout << '\n';
		{
			DiamondTrap	clone(rough);
		}
		std::cout << '\n';
		{
			DiamondTrap clone = rough;
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	DiamondTrap diana("Diana");

	diana.attack("the queen");
	diana.beRepaired(5);
	diana.takeDamage(25);
	diana.takeDamage(80);
	diana.beRepaired(5);
	std::cout << '\n';
	diana.highFivesGuys();
	diana.guardGate();
	diana.whoAmI();
}
