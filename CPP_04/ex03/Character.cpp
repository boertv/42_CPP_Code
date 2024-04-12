#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Character::Character()
	: _name("Joe")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
	: _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const& src)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->operator=(src);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

Character& Character::operator=(Character const& rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

/* GETTERS AND SETTERS */
std::string const&	Character::getName() const {
	return this->_name; }

/* MEMBER FUNCTIONS */
void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			continue;
		this->_inventory[i] = m;
		break;
	}
}

void	Character::unequip(int idx)
{
	if (!this->_inventory[idx])
		return;
	int	i = 0;
	while (i < 10)
	{
		if (!AMateria::floor[i])
			break;
		i++;
	}
	if (i == 10)
	{
		std::cout << "the floor is already full of garbage\n";
		return;
	}
	AMateria::floor[i] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!this->_inventory[idx])
		return;
	this->_inventory[idx]->use(target);
}
