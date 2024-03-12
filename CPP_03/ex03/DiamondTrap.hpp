#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap	: public ScavTrap, public FragTrap
{
	std::string	_name;
	using FragTrap::_hp;
	using ScavTrap::_energy;
	using FragTrap::_attack;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();

	DiamondTrap&	operator=(DiamondTrap const& rhs);

	using	ScavTrap::attack;
	void	whoAmI();
};

#endif
