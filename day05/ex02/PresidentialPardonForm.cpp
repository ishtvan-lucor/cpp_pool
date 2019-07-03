//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):
	Form(copy.getName(), copy.getGradeToSigned(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &target)
{
	this->_target = target.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}