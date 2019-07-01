//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(cons std, ::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &target)
{
	this->_grade = target.getGraade();
}

Bureaucrat::~ ~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGraade() const
{
	return this->_grade;
}

void Bureaucrat::operator++()
{
	if (this->_grade - 1 < 1)
		throw() Bureaucrat::GradeTooHighException();
	else
	this->_grade--;
}

void Bureaucrat::operator--()
{
	if (this->_grade + 1 > 150)
		throw() Bureaucrat::GradeTooLowException();
	else
	this->_grade++;
}

std::ostream &operator<<(std::ostream out,Bureaucrat const & target)
{
	return (out << target.getName() << ", bureaucrat grade " << target.getGraade() << std::endl);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error : Bureaucrat grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error : Bureaucrat grade too low!");
}