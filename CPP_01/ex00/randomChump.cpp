#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	little_guy = Zombie(name);

	little_guy.announce();
}
