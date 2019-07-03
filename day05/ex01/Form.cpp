//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#include "Form.hpp"

Form::Form(std::string name, int gradeToSigned, int gradeToExecute): _name(name),
	_sign(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSigned < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSigned > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &copy): _gradeToSigned(copy.getGradeToSigned()),
	_gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

Form& Form::operator=(Form const &target)
{
	this->_sign = target.getSign();
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

int Form::getGradeToSigned() const
{
	return this	->_gradeToSigned;
}

bool Form::getSign() const
{
	return this->_sign;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSigned)
		throw GradeTooLowException();
	this->_sign = true;
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low for form!");
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high for form!");
}


std::ostream &operator<<(std::ostream &out, Form const &target)
{
	out << "Form " << target.getName() << ": grade to sign [" << target.getGradeToSigned()
	<< "], grade to execute [" << target.getGradeToExecute() << "], signed: ";
	if (target.getSign())
		out << "yes.";
	else
		out << "no.";
	return out;
}

