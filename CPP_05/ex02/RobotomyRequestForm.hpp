#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	static bool	_first_run;
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);

	void	concrete_execute() const;
};

#endif
