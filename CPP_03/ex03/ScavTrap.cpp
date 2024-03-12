#include "ScavTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
static void	constructor_msg(std::string name) {
	std::cout << "built a brand new ScavTrap: " << name << "\n"; }

ScavTrap::ScavTrap()
	: ClapTrap("Vault Hunter", 100, 50, 20), _guarding(false) {
		constructor_msg(this->_name); }

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20), _guarding(false) {
		constructor_msg(this->_name); }

ScavTrap::ScavTrap(ScavTrap const& src)
	: ClapTrap(src), _guarding(src._guarding) {
		constructor_msg(this->_name); }

ScavTrap::~ScavTrap() {
	std::cout << "scrapping ScavTrap: " << this->_name << " \n"; }

/* OPERATOR OVERLOADS */
ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;
	this->_guarding = rhs._guarding;
	return *this;
}

/* MEMBER FUNCTIONS */

// static util functions
static void	eepy(std::string name) {
	std::cout << name << " is an eepy scav .. (no energy)\n"; }

static void	dead(std::string name) {
	std::cout << name << " is not moving like a scav anymore .. (no hp)\n"; }

// actual members
void	ScavTrap::attack(const std::string& target)
{
	if (!this->_hp)
		return dead(this->_name);
	if (!this->_energy)
		return eepy(this->_name);
	this->_energy--;
	std::cout << this->_name << " scav-attacks " << target << " for " << this->_attack << "!";
	if (!this->_attack)
		std::cout << " ... it's not very effective";
	std::cout << '\n';
}

void	ScavTrap::guardGate()
{
	if (this->_guarding)
		return (void) (std::cout << this->_name << " is already keeping the gate\n");
	this->_guarding = true;
	std::cout << this->_name << " is now in gate keeper mode\n";
}
