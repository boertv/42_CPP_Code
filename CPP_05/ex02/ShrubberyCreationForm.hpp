#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);

	void	concrete_execute(Bureaucrat const& executor) const;
};

#endif
