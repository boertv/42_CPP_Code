#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	Cat(Cat const& src);
	~Cat();
	Cat&	operator=(Cat const& rhs);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
