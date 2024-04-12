#include "Animal.hpp"
#include <iostream>

/* CONSTRUCTORS AND '=' OVERLOAD */
Animal::Animal()
	: type("ditto") {
	std::cout << "a new Animal was born\n"; }

Animal::Animal(std::string type)
	: type(type) {
	std::cout << "a new Animal was born\n"; }

Animal::Animal(Animal const& src)
	: type(src.type) {
	std::cout << "a new Animal was born\n"; }

Animal::~Animal() {
	std::cout << "an Animal retired to a farm\n"; }

Animal&	Animal::operator=(Animal const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
void	Animal::makeSound() const
{
	std::cout << "skrrrrrrrrt\n";
}

std::string	Animal::getType() const
{
	return this->type;
}
