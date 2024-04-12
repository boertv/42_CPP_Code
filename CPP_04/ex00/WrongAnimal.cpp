#include "WrongAnimal.hpp"
#include <iostream>

/* CONSTRUCTORS AND '=' OVERLOAD */
WrongAnimal::WrongAnimal()
	: type("WrongAnimal") {
	std::cout << "a new WrongAnimal was born\n"; }

WrongAnimal::WrongAnimal(std::string type)
	: type(type) {
	std::cout << "a new WrongAnimal was born\n"; }

WrongAnimal::WrongAnimal(WrongAnimal const& src)
	: type(src.type) {
	std::cout << "a new WrongAnimal was born\n"; }

WrongAnimal::~WrongAnimal() {
	std::cout << "a WrongAnimal retired to a farm\n"; }

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
void	WrongAnimal::makeSound() const
{
	std::cout << "nonono this animal is all wrong!!\n";
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
