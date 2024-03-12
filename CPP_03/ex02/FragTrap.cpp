#include "FragTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
static void	constructor_msg(std::string name) {
	std::cout << "built a brand new FragTrap: " << name << "\n"; }

FragTrap::FragTrap()
	: ClapTrap("Vault Hunter", 100, 100, 30) {
		constructor_msg(this->_name); }

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30) {
		constructor_msg(this->_name); }

FragTrap::FragTrap(FragTrap const& src)
	: ClapTrap(src) {
		constructor_msg(this->_name); }

FragTrap::~FragTrap() {
	std::cout << "scrapping FragTrap: " << this->_name << " \n"; }

/* OPERATOR OVERLOADS */
FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;
	return *this;
}

/* MEMBER FUNCTIONS */
void	FragTrap::highFivesGuys() {
	std::cout << "woooooooo nice jobs guys!! this positively deserves a high five!\n"; }
