#include "Cat.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Cat::Cat()
	: AAnimal("Cat") {
	std::cout << "the animal grew up to be a Cat\n"; }
Cat::Cat(Cat const& src)
	: AAnimal(src.type) {
	std::cout << "the animal grew up to be a Cat\n"; }
Cat::~Cat() {
	std::cout << "a Cat grew old\n"; }

Cat&	Cat::operator=(Cat const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
void	Cat::makeSound() const
{
	std::cout << "miaaaauw\n";
}

std::string	Cat::getType() const
{
	return this->type;
}
