//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#ifndef CPP_POOL_SHRUBBERYCREATIONFORM_HPP
#define CPP_POOL_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string	_target;

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const & target);
	virtual ~ShrubberyCreationForm();

	std::string		getTarget(void) const;
	virtual void	action(void) const;
};

#endif //CPP_POOL_SHRUBBERYCREATIONFORM_HPP
