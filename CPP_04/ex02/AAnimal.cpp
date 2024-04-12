#include "AAnimal.hpp"
#include <iostream>

/* CONSTRUCTORS AND '=' OVERLOAD */
AAnimal::AAnimal()
	: type("ditto") {
	std::cout << "a new AAnimal was born\n"; }

AAnimal::AAnimal(std::string type)
	: type(type) {
	std::cout << "a new AAnimal was born\n"; }

AAnimal::AAnimal(AAnimal const& src)
	: type(src.type) {
	std::cout << "a new AAnimal was born\n"; }

AAnimal::~AAnimal() {
	std::cout << "an AAnimal retired to a farm\n"; }

AAnimal&	AAnimal::operator=(AAnimal const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
std::string	AAnimal::getType() const
{
	return this->type;
}
