#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const& src);
	~Cure();
	Cure& operator=(Cure const& rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
