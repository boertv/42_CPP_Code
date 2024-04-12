#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

/* CONSTRUCTORS AND = OVERLOAD */
Cure::Cure()
	: AMateria("cure") {}

Cure::Cure(Cure const& src)
	: AMateria("cure") {
	this->operator=(src); }

Cure::~Cure() {}

Cure& Cure::operator=(Cure const& rhs)
{
	this->AMateria::operator=(rhs);
	return *this;
}

/* MEMBER FUNCTIONS */
AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
