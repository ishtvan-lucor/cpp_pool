/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:10:07 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/06/25 18:56:29 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy_phonebook.h"

void		add_contact(Contact *current)
{
	std::string	buffer;

	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, buffer);
	current->setFirstName(buffer);

	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, buffer);
	current->setLastName(buffer);

	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, buffer);
	current->setNickname(buffer);

	std::cout << "Enter login:" << std::endl;
	std::getline(std::cin, buffer);
	current->setLogin(buffer);

	std::cout << "Enter postal address:" << std::endl;
	std::getline(std::cin, buffer);
	current->setPostalAddress(buffer);

	std::cout << "Enter email address:" << std::endl;
	std::getline(std::cin, buffer);
	current->setEmailAddress(buffer);

	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, buffer);
	current->setPhoneNumber(buffer);

	std::cout << "Enter birthday date:" << std::endl;
	std::getline(std::cin, buffer);
	current->setBirthdayDate(buffer);

	std::cout << "Enter favorite meal:" << std::endl;
	std::getline(std::cin, buffer);
	current->setFavoriteMeal(buffer);

	std::cout << "Enter underwear color:" << std::endl;
	std::getline(std::cin, buffer);
	current->setUnderwearColor(buffer);

	std::cout << "Enter darkest secret:" << std::endl;
	std::getline(std::cin, buffer);
	current->setDarkestSecret(buffer);
	std::cout << "You have new friend=)" << std::endl;
}

std::string	truncatedString(std::string str)
{
	if (str.length() > WIDHT)
		return (str.substr(0, (WIDHT - 1)) + '.');
	return (str);
}

void		displayListContact(Contact *phonebook)
{
	std::cout << "+" << std::setw(WIDHT * 4 + 4) << std::setfill('-');
	std::cout << '+' << std::setfill(' ') << std::endl;

	std::cout << "|" << std::setw(WIDHT);
	std::cout << "Index" << "|" << std::setw(WIDHT);
	std::cout << "First name" << "|" << std::setw(WIDHT);
	std::cout << "Last name" << "|" << std::setw(WIDHT);
	std::cout << "Nickname" << "|" << std::endl;

	std::cout << "+" << std::setw(WIDHT * 4 + 4) << std::setfill('-');
	std::cout << '+' << std::setfill(' ') << std::endl;

	for (int i = 0; i < MAX_CONTACT; i++)
	{
		std::cout << "|" << std::setw(WIDHT);
		std::cout << i << "|" << std::setw(WIDHT);
		std::cout << truncatedString(phonebook[i].getFirstName());
		std::cout << "|" << std::setw(WIDHT);
		std::cout << truncatedString(phonebook[i].getLastName());
		std::cout << "|" << std::setw(WIDHT);
		std::cout << truncatedString(phonebook[i].getNickname());
		std::cout << "|" << std::endl;

		std::cout << "+" << std::setw(WIDHT * 4 + 4) << std::setfill('-');
		std::cout << '+' << std::setfill(' ') << std::endl;
	}
}

int			displayContactById(int max_cur, Contact *phonebook)
{
	int			id;

	std::cin >> id;
	if (std::cin.eof())
		return 1;
	if (id >= 0 && id < max_cur)
		phonebook[id].displayContact();
	else
		std::cout << "Wrong contact, my dear(" << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	return 0;
}

int			main(void)
{
	Contact		phonebook[MAX_CONTACT];
	std::string	command;
	int			id = 0;

	std::cout << "Welcome back to 80's!"<< std::endl
	<< "It's crappy phonebook softwere!" << std::endl;

	while (1)
	{
		std::cout << "Enter command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, command);
		if (!command.compare("EXIT") || std::cin.eof())
			break;
		else if (!command.compare("ADD")) {
			if (id < MAX_CONTACT)
			{
				add_contact(&phonebook[id]);
				id++;
			} else
				std::cout << "You have maximum contacts! 80's=)" << std::endl;
		}
		else if (!command.compare("SEARCH"))
		{
			displayListContact(phonebook);
			std::cout << "Select the contact id:" << std::endl;
			if (displayContactById(id, phonebook))
				return 0;
		}
		else
			std::cout << "By Thore! By Odin! Use your brain!" << std::endl;
	}
	return 0;
}