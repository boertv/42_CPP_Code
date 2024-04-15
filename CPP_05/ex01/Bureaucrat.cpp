#include "Bureaucrat.hpp"
#include "Form.hpp"

/* CONSTRUCTORS */
Bureaucrat::Bureaucrat()
	: _name("John"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) {
	this->operator=(src); }

Bureaucrat::~Bureaucrat() {}

/* OPERATOR OVERLOADS */
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const& rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return stream;
}

/* GETTERS AND SETTERS */
std::string	Bureaucrat::getName() const {
	return this->_name; }

int	Bureaucrat::getGrade() const {
	return this->_grade; }

/* MEMBER FUNCTIONS */
void	Bureaucrat::promote()
{
	if (_grade <= 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade >= 150)
		throw (GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(Form& form) throw()
{
	if (form.getSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because it is already signed.\n";
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << ".\n";
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << ".\n";
	}
}


/* EXCEPTION CLASSES */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low"; }
