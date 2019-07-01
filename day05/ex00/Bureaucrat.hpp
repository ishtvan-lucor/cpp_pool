//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#ifndef WAR_BUREAUCRAT_HPP
#define WAR_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(cons std::string name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const & target);
	~Bureaucrat();

	std::string		getName( void ) const;
	int				getGraade( void) const;

	void			operator++( void ) ;
	void			operator--( void );

class GradeTooHighException : public std::exception
{
	virtual const char *what const throw();
};

class GradeTooLowException : public  std::exception
{
	virtual const char *what consyt throw();
};

};

std::ostream &operator<<(std::string &out, Bureaucrat const &target);

#endif //WAR_BUREAUCRAT_HPP
