//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):
	Form(copy.getName(), copy.getGradeToSigned(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &target)
{
	this->_target = target.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::action() const
{
	std::string		fileName = this->getTarget() + "_shrubbery";
	std::ofstream		out(fileName);
	out << "\n"
		   "                                  # #### ####\n"
		   "                                ### \\/#|### |/####\n"
		   "                               ##\\/#/ \\||/##/_/##/_#\n"
		   "                             ###  \\/###|/ \\/ # ###\n"
		   "                           ##_\\_#\\_\\## | #/###_/_####\n"
		   "                          ## #### # \\ #| /  #### ##/##\n"
		   "                           __#_--###`  |{,###---###-~\n"
		   "                                     \\ }{\n"
		   "                                      }}{\n"
		   "                                      }}{\n"
		   "                                 ejm  {{}\n"
		   "                                , -=-~{ .-^- _\n"
		   "                                      `}\n"
		   "                                       {";
	out << std::endl;
	out.close();
}