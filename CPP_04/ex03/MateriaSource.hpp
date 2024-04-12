#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria	*_book[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const& src);
	~MateriaSource();
	MateriaSource& operator=(MateriaSource const& rhs);

	void		learnMateria(AMateria* mat);
	AMateria*	createMateria(std::string const& type);
};

#endif
