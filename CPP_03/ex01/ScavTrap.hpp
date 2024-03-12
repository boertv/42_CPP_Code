#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap	: public ClapTrap
{
	bool	_guarding;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& src);
	~ScavTrap();

	ScavTrap&	operator=(ScavTrap const& rhs);

	void	attack(const std::string& target);
	void	guardGate();
};

#endif
