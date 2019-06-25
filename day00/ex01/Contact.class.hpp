/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:27:33 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/25 16:23:33 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>
#include <string>

class Contact
{
public:
	Contact( void );
	~Contact( void );

	void		displayContact( void );
	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getLogin( void ) const;
	std::string	getPostalAddress( void ) const;
	std::string	getEmailAddress( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getBirthdayDate( void ) const;
	std::string	getFavoriteMeal( void ) const;
	std::string	getUnderwearColor( void ) const;
	std::string	getDarkestSecret( void ) const;
	void		setFirstName( std::string);
	void		setLastName( std::string);
	void		setNickname( std::string);
	void		setLogin( std::string);
	void		setPostalAddress( std::string);
	void		setEmailAddress( std::string);
	void		setPhoneNumber( std::string);
	void		setBirthdayDate( std::string);
	void		setFavoriteMeal( std::string);
	void		setUnderwearColor( std::string);
	void		setDarkestSecret( std::string);

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_postal_address;
	std::string	_email_address;
	std::string	_phone_number;
	std::string	_birthday_date;
	std::string	_favorite_meal;
	std::string	_underwear_color;
	std::string	_darkest_secret;
};

#endif //CONTACTC_CLASSS_H
