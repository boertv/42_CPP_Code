#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal
{
protected:
	std::string	type;
	Animal(std::string type);

public:
	Animal();
	Animal(Animal const& src);
	virtual	~Animal();
	Animal&	operator=(Animal const& rhs);

	virtual void		makeSound() const;
	virtual std::string	getType() const;
};

#endif
