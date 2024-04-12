#include "Dog.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Dog::Dog()
	: Animal("Dog"), brain(new Brain()) {
	std::cout << "the animal grew up to be a Dog\n"; }
Dog::Dog(Dog const& src)
	: Animal(src.type), brain(new Brain(*src.brain)) {
	std::cout << "the animal grew up to be a Dog\n"; }
Dog::~Dog() {
	std::cout << "a Dog grew old\n";
	delete this->brain; }

Dog&	Dog::operator=(Dog const& rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
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
