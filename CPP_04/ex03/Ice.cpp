#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Ice::Ice()
	: AMateria("ice") {}

Ice::Ice(Ice const& src)
	: AMateria("ice") {
	this->operator=(src); }

Ice::~Ice() {}

Ice& Ice::operator=(Ice const& rhs)
{
	this->AMateria::operator=(rhs);
	return *this;
}

/* MEMBER FUNCTIONS */
AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
