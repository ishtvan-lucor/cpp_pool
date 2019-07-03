//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#ifndef WAR_BUREAUCRAT_HPP
#define WAR_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const & target);
	~Bureaucrat();

	std::string		getName( void ) const;
	int				getGrade( void) const;

	Bureaucrat			&operator++( void );
	Bureaucrat			&operator--( void );

	void				signForm(Form &form);

	void				executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &target);

#endif //WAR_BUREAUCRAT_HPP
