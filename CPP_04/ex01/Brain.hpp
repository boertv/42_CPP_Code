#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain
{
	std::string	ideas[100];

public:
	Brain();
	Brain(Brain const& src);
	~Brain();
	Brain&	operator=(Brain const& rhs);
};

#endif
