/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:27:25 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/25 17:46:27 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.class.hpp"

Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

void		Contact::displayContact()
{
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Login: " << getLogin() << std::endl;
	std::cout << "Postal adress: " << getPostalAddress() << std::endl;
	std::cout << "Email adress: " << getEmailAddress() << std::endl;
	std::cout << "Phone number: " << getPhoneNumber() << std::endl;
	std::cout << "Birthday date: " << getBirthdayDate() << std::endl;
	std::cout << "Favorite meal: " << getFavoriteMeal() << std::endl;
	std::cout << "Underwear color: " << getUnderwearColor() << std::endl;
	std::cout << "Darkest secret: " << getDarkestSecret() << std::endl;
}

std::string	Contact::getFirstName() const
{
	return this->_first_name;
}

std::string	Contact::getLastName() const
{
	return this->_last_name;
}

std::string	Contact::getNickname() const
{
	return this->_nickname;
}

std::string	Contact::getLogin() const
{
	return this->_login;
}

std::string	Contact::getPostalAddress() const
{
	return this->_postal_address;
}

std::string	Contact::getEmailAddress() const
{
	return this->_email_address;
}

std::string	Contact::getPhoneNumber() const
{
	return this->_phone_number;
}

std::string	Contact::getBirthdayDate() const
{
	return this->_birthday_date;
}

std::string	Contact::getFavoriteMeal() const
{
	return this->_favorite_meal;
}

std::string	Contact::getUnderwearColor() const
{
	return this->_underwear_color;
}

std::string	Contact::getDarkestSecret() const
{
	return this->_darkest_secret;
}

void Contact::setFirstName ( std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName ( std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::setNickname ( std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::setLogin ( std::string login)
{
	this->_login = login;
}

void Contact::setPostalAddress ( std::string postal_address)
{
	this->_postal_address = postal_address;
}

void Contact::setEmailAddress ( std::string email_address)
{
	this->_email_address = email_address;
}

void Contact::setPhoneNumber ( std::string phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::setBirthdayDate ( std::string birthday_date)
{
	this->_birthday_date = birthday_date;
}

void Contact::setFavoriteMeal ( std::string favorite_meal)
{
	this->_favorite_meal = favorite_meal;
}

void Contact::setUnderwearColor ( std::string underwear_color)
{
	this->_underwear_color = underwear_color;
}

void Contact::setDarkestSecret ( std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
