#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	{
		ClapTrap	hunter;
		ClapTrap	jeff("jeff");
		{
			ClapTrap	clone(jeff);
		}
		std::cout << '\n';

		hunter.attack("jeff");
		jeff.takeDamage(0);
		std::cout << '\n';

		hunter.takeDamage(100);
		hunter.beRepaired(100);
		hunter.attack("jeff");
		jeff.takeDamage(3);
		jeff.takeDamage(3);
		jeff.takeDamage(3);
		jeff.beRepaired(3);
		jeff.takeDamage(3);
		jeff.takeDamage(3);
	}
	std::cout << '\n';

	{
		ClapTrap	quixote("quixote");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.attack("windmill");
		quixote.beRepaired(10);
		quixote.attack("windmill");
	}
	std::cout << '\n';

	{
		ClapTrap	pyrrhus("pyrrhus");
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.beRepaired(10);
		pyrrhus.takeDamage(100);
		pyrrhus.takeDamage(10);
	}
}
