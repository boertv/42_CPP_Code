#include "WrongCat.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {
	std::cout << "the animal grew up to be a WrongCat\n"; }
WrongCat::WrongCat(WrongCat const& src)
	: WrongAnimal(src.type) {
	std::cout << "the animal grew up to be a WrongCat\n"; }
WrongCat::~WrongCat() {
	std::cout << "a WrongCat grew old\n"; }

WrongCat&	WrongCat::operator=(WrongCat const& rhs)
{
	this->type = rhs.type;
	return *this;
}

/* MEMBER FUNCTIONS */
void	WrongCat::makeSound() const
{
	std::cout << "yikes what a demon this cat is\n";
}

std::string	WrongCat::getType() const
{
	return this->type;
}
