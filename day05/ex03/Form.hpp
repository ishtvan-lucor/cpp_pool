//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-03.
//

#ifndef CPP_POOL_FORM_HPP
#define CPP_POOL_FORM_HPP


#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeToSigned;
	const int			_gradeToExecute;

public:
	Form(std::string name, int gradeToSigned, int gradeToExecute);
	Form(Form const & copy);
	Form &operator=(Form const & target);
	virtual ~Form();

	std::string		getName( void ) const;
	bool			getSign( void ) const;
	int				getGradeToSigned( void ) const;
	int				getGradeToExecute( void ) const;

	void			beSigned(Bureaucrat const & bureaucrat);

	void			execute(Bureaucrat const & executor) const;
	virtual void	action(void) const = 0;

	class GradeTooHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &target);

#endif //CPP_POOL_FORM_HPP
