//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("Robotomy Request Form", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):
	Form(copy.getName(), copy.getGradeToSigned(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &target)
{
	this->_target = target.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::action() const
{
	std::cout << "* drilling noises *" << std::endl;
	if ((rand() % 1) % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has failed" << std::endl;
}