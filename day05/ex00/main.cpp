//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-01.
//

#include "Bureaucrat.hpp"

#include <iostream>

int main( void ) {

	Bureaucrat boss = Bureaucrat("Boss", 1);
	std::cout << boss;
	Bureaucrat jerk = Bureaucrat("Jerk", 150);
	std::cout << jerk;
	Bureaucrat petya = Bureaucrat("Petya", 34);
	std::cout << petya;

	try {
		std::cout  << "+ 1 grade to Boss" << std::endl;
		boss += 1;
		std::cout << boss;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout  << "Boss++" << std::endl;
		boss++;
		std::cout << boss;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout  << "- 1 grade to Jerk" << std::endl;
		jerk -= 1;
		std::cout << jerk;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "--Jerk" << std::endl;
		--jerk;
		std::cout << jerk;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "+ 6 grade to Petya" << std::endl;
		petya += 6;
		std::cout << petya;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "++Petya" << std::endl;
		++petya;
		std::cout << petya;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Petya--" << std::endl;
		petya--;
		std::cout << petya;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Create copy from Boss" << std::endl;
	Bureaucrat copyBoss = Bureaucrat(boss);
	std::cout << copyBoss;


	return (0);
}