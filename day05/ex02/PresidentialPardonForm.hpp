//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#ifndef CPP_POOL_PRESIDENTIALPARDONFORM_HPP
#define CPP_POOL_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <fstream>

class PresidentialPardonForm : public Form
{
private:
	std::string	_target;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const & target);
	virtual ~PresidentialPardonForm();

	std::string		getTarget(void) const;
	virtual void	action(void) const;
};


#endif //CPP_POOL_PRESIDENTIALPARDONFORM_HPP
