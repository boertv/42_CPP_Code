#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS */
AForm::AForm()
	: _name("basic form"), _signed(false), _grade_sign(150), _grade_exec(150) {}

AForm::AForm(std::string const& name, int const grade_sign, int const grade_exec)
	: _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign > 150 || grade_exec > 150)
		throw (GradeTooLowException());
	if (grade_sign < 1 || grade_exec < 1)
		throw (GradeTooHighException());
}

AForm::AForm(AForm const& src)
	: _name(src._name), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec) {
	*this = src; }

AForm::~AForm() {}

/* OPERATOR OVERLOADS */
AForm& AForm::operator=(AForm const& rhs)
{
	_signed = rhs._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, AForm const& rhs)
{
	stream << rhs.getName() << " (signed: " << rhs.getSigned() << ", grade to sign: " << rhs.getGradeSign();
	stream << ", grade to execute: " << rhs.getGradeExec() << ")";
	return stream;
}

/* GETTERS */
std::string	AForm::getName() const {
	return _name; }

bool	AForm::getSigned() const {
	return _signed; }

int		AForm::getGradeSign() const {
	return _grade_sign; }

int		AForm::getGradeExec() const {
	return _grade_exec; }

/* MEMBER FUNCTIONS */
void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (_signed)
		return ;
	if (bureaucrat.getGrade() > _grade_sign)
		throw (GradeTooLowException());
	_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw (NotSignedException());
	if (executor.getGrade() > _grade_exec)
		throw (GradeTooLowException());
	this->concrete_execute(executor);
}


/* EXCEPTION CLASSES */
const char *AForm::GradeTooHighException::what() const throw() {
	return "grade too high"; }

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade too low"; }

const char *AForm::NotSignedException::what() const throw() {
	return "not signed"; }
