#include "Bureaucrat.hpp"

/* CONSTRUCTORS AND '=' OVERLOAD */
Bureaucrat::Bureaucrat()
	: name("John"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) {
	this->operator=(src); }

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	this->grade = rhs.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const& rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return stream;
}

/* GETTERS AND SETTERS */
std::string	Bureaucrat::getName() const {
	return this->name; }

int	Bureaucrat::getGrade() const {
	return this->grade; }

/* MEMBER FUNCTIONS */
void	Bureaucrat::promote()
{
	if (grade <= 1)
		throw (GradeTooHighException());
	grade--;
}

void	Bureaucrat::demote()
{
	if (grade >= 150)
		throw (GradeTooLowException());
	grade++;
}


/* EXCEPTION CLASSES */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low"; }
