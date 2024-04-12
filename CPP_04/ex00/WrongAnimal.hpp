#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal
{
protected:
	std::string	type;
	WrongAnimal(std::string type);

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const& src);
	virtual ~WrongAnimal();
	WrongAnimal&	operator=(WrongAnimal const& rhs);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
