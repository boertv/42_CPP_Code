#include "MateriaSource.hpp"
#include "AMateria.hpp"

/* CONSTRUCTORS AND = OVERLOAD */
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_book[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	for (int i = 0; i < 4; i++)
		this->_book[i] = NULL;
	this->operator=(src);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_book[i];
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_book[i];
		if (rhs._book[i])
			this->_book[i] = rhs._book[i]->clone();
	}
	return *this;
}

/* MEMBER FUNCTIONS */
void	MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_book[i])
			continue;
		this->_book[i] = mat;
		break;
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int	i = 0;
	while (i < 4)
	{
		if (!type.compare(this->_book[i]->getType()))
			break;
		i++;
	}
	if (i == 4)
		return NULL;
	return (this->_book[i]->clone());
}
