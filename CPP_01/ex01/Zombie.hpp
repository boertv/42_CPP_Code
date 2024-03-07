#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	std::string	name;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce();
	void	set_name(std::string name);
};

#endif
