#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_first_run = false;

/* CONSTRUCTORS */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy request", 72, 45), _target("human") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	: AForm("robotomy request", 72, 45) {
	this->operator=(src); }

RobotomyRequestForm::~RobotomyRequestForm() {}

/* OPERATOR OVERLOADS */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	_target = rhs._target;
	this->AForm::operator=(rhs);
	return *this;
}

/* MEMBER FUNCTIONS */
void	RobotomyRequestForm::concrete_execute() const
{
	if (!_first_run)
	{
		_first_run = true;
		srand(time(0));
	}
	std::cout << "  *brrrrrrrrrt\tbzzzzt*\n";
	if (rand() % 2)
		std::cout << "failed to robotomize " << _target << ".\n";
	else
		std::cout << _target << " has been robotomized successfully!\n";
}
