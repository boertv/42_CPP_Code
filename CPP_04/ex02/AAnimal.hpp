#ifndef AANIMAL_H
# define AANIMAL_H

#include <string>

class AAnimal
{
protected:
	std::string	type;
	AAnimal(std::string type);

public:
	AAnimal();
	AAnimal(AAnimal const& src);
	virtual	~AAnimal();
	AAnimal&	operator=(AAnimal const& rhs);

	virtual void		makeSound() const = 0;
	virtual std::string	getType() const;
};

#endif
