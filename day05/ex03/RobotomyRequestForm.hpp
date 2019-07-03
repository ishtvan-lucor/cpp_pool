//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#ifndef CPP_POOL_ROBOTOMYREQUESTFORM_HPP
#define CPP_POOL_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <fstream>

class RobotomyRequestForm : public Form
{
private:
	std::string	_target;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const & target);
	virtual ~RobotomyRequestForm();

	std::string		getTarget(void) const;
	virtual void	action(void) const;
};

#endif //CPP_POOL_ROBOTOMYREQUESTFORM_HPP
