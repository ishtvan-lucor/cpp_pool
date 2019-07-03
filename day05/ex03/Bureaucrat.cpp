//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
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
	this->_grade = target.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat &Bureaucrat::operator++()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	this->_grade--;
	return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	this->_grade++;
	return *this;
}

void	Bureaucrat::signForm (Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << this->_name << " cannot sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error : Bureaucrat grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error : Bureaucrat grade too low!");
}

std::ostream &operator<<(std::ostream &out,Bureaucrat const & target)
{
	out << target.getName() << ", bureaucrat grade " << target.getGrade();
	return out;
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		if (form.getSign())
		{
			form.execute(*this);
			std::cout << this->_name << " executes " << form.getName() << std::endl;
		}
		else
			std::cout << form.getName() << " don't signed" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " cannot execute " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}