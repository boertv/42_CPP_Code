#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), pweapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	if (!this->pweapon)
		std::cout << "fists";
	else
		std::cout << (*this->pweapon).getType();
	std::cout << '\n';
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->pweapon = &weapon;
}
