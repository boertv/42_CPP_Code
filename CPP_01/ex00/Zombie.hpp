#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	std::string	name;

	public:
	Zombie(std::string name);
	~Zombie();

	void	announce();
};

#endif
