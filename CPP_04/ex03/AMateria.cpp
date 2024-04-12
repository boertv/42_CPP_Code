#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

int			AMateria::this_count = 0;
AMateria	*AMateria::floor[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* CONSTRUCTORS AND = OVERLOAD */
AMateria::AMateria()
	:type("blank") {
	AMateria::this_count++; }

AMateria::AMateria(std::string const& type)
	: type(type) {
	AMateria::this_count++; }

AMateria::AMateria(AMateria const& src) {
	this->operator=(src);
	AMateria::this_count++; }

AMateria::~AMateria()
{
	AMateria::this_count--;
	if (!AMateria::this_count)
	{
		for (int i = 0; i < 10; i++)
			delete AMateria::floor[i];
	}
}

AMateria&	AMateria::operator=(AMateria const& rhs)
{
	(void) rhs;
	return *this;
}

/* GETTERS AND SETTERS */
std::string const&	AMateria::getType() const {
	return this->type; }

/* MEMBER FUNCTIONS */
void	AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " was affected by " << this->type << "\n";
}
