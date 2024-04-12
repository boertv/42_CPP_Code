#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain*	brain;

public:
	Dog();
	Dog(Dog const& src);
	~Dog();
	Dog&	operator=(Dog const& rhs);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
