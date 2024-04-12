#include "Dog.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Dog::Dog()
	: AAnimal("Dog") {
	std::cout << "the animal grew up to be a Dog\n"; }
Dog::Dog(Dog const& src)
	: AAnimal(src.type) {
	std::cout << "the animal grew up to be a Dog\n"; }
Dog::~Dog() {
	std::cout << "a Dog grew old\n"; }

Dog&	Dog::operator=(Dog const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
void	Dog::makeSound() const
{
	std::cout << "bark bark\n";
}

std::string	Dog::getType() const
{
	return this->type;
}
