#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain*	brain;

public:
	Cat();
	Cat(Cat const& src);
	~Cat();
	Cat&	operator=(Cat const& rhs);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
