#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>

class	ClapTrap
{
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_energy;
	unsigned int	_attack;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();

	ClapTrap&	operator=(ClapTrap const& rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
