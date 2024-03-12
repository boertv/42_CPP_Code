#include "DiamondTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
static void	constructor_msg(std::string name) {
	std::cout << "built a shiny new DiamondTrap: " << name << '\n'; }

DiamondTrap::DiamondTrap()
	: ClapTrap("Diamond Hunter_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("Diamond Hunter") {
		constructor_msg(this->_name); }

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name(name) {
		constructor_msg(this->_name); }

DiamondTrap::DiamondTrap(DiamondTrap const& src)
	: ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
		constructor_msg(this->_name); }

DiamondTrap::~DiamondTrap() {
	std::cout << "burning DiamondTrap: " << this->_name << '\n'; }

/* OPERATOR OVERLOADS */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& rhs)
{
	this->_name = rhs._name;
	this->FragTrap::_hp = rhs._hp;
	this->ScavTrap::_energy = rhs._energy;
	this->FragTrap::_attack = rhs._attack;
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	return *this;
}

/* MEMBER FUNCTIONS */
void	DiamondTrap::whoAmI() {
	std::cout << "my name is " << this->_name << "!  ... or is it " << this->ClapTrap::_name << "?\n"; }
