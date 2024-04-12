#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(Dog const& src);
	~Dog();
	Dog&	operator=(Dog const& rhs);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
