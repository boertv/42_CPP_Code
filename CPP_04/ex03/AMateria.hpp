#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
class ICharacter;

class AMateria
{
protected:
	static int		this_count;
	std::string		type;

public:
	static AMateria	*floor[];

	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const& src);
	virtual ~AMateria();
	AMateria&	operator=(AMateria const& rhs);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
