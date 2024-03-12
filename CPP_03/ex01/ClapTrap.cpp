#include "ClapTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
static void	constructor_msg(std::string name) {
	std::cout << "built a brand new ClapTrap: " << name << "\n"; }

ClapTrap::ClapTrap()
	: _name("Vault Hunter"), _hp(10), _energy(10), _attack(0) {
		constructor_msg(this->_name); }

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hp(10), _energy(10), _attack(0) {
		constructor_msg(this->_name); }

ClapTrap::ClapTrap(ClapTrap const& src)
	: _name(src._name), _hp(src._hp), _energy(src._energy), _attack(src._attack) {
		constructor_msg(this->_name); }

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int attack)
	: _name(name), _hp(hp), _energy(energy), _attack(attack) {
		constructor_msg(this->_name); }

ClapTrap::~ClapTrap() {
	std::cout << "scrapping ClapTrap: " << this->_name << " \n"; }

/* OPERATOR OVERLOADS */
ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;
	return *this;
}

/* MEMBER FUNCTIONS */

// static util functions
static void	eepy(std::string name) {
	std::cout << name << " so eepy .. (no energy)\n"; }

static void	dead(std::string name) {
	std::cout << name << " is not moving anymore .. (no hp)\n"; }

// actual members
void	ClapTrap::attack(const std::string& target)
{
	if (!this->_hp)
		return dead(this->_name);
	if (!this->_energy)
		return eepy(this->_name);
	this->_energy--;
	std::cout << this->_name << " attacks " << target << " for " << this->_attack << "!";
	if (!this->_attack)
		std::cout << " ... it's not very effective";
	std::cout << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hp)
		return (void) (std::cout << this->_name << " is already dead!\n");
	if (amount >= this->_hp)
	{
		this->_hp = 0;
		std::cout << "the attack of " << amount << " was too much for " << this->_name << "!\n";
		return;
	}
	this->_hp -= amount;
	std::cout << this->_name << " was hit for " << amount << "!";
	if (!amount)
		std::cout << " ... hahaha you missed!";
	std::cout << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hp)
		return dead(this->_name);
	if (!this->_energy)
		return eepy(this->_name);
	this->_energy--;
	this->_hp += amount;
	std::cout << this->_name << " repairs itself for " << amount;
	if (!amount)
		std::cout << " ... nothing seems to have changed";
	std::cout << '\n';
}
