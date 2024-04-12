#include "Cat.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Cat::Cat()
	: Animal("Cat"), brain(new Brain()) {
	std::cout << "the animal grew up to be a Cat\n"; }
Cat::Cat(Cat const& src)
	: Animal(src.type), brain(new Brain(*src.brain)) {
	std::cout << "the animal grew up to be a Cat\n"; }
Cat::~Cat() {
	std::cout << "a Cat grew old\n";
	delete this->brain; }

Cat&	Cat::operator=(Cat const& rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
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
