#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: name(name) {}

Zombie::~Zombie()
{
	std::cout << "deleting " << this->name << '\n';
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}
