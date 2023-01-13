/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:20:51 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/12 12:07:04 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "PhoneBook.hpp"

int main(void)
{
	bool		exit;
	PhoneBook	phonebook;
	std::string	action;
	int			index;

	exit = false;
	phonebook.printPhonebook();
	phonebook.printActions();
	while (!exit)
	{
		std::cout << "action: ";
		std::getline(std::cin, action);
		if (!action.compare("ADD") || !action.compare("add"))
		{
			phonebook.addContact();
			phonebook.printPhonebook();
		}
		else if (!action.compare("SEARCH") || !action.compare("search"))
		{
			phonebook.printPhonebook();
			if (phonebook.getNbContacts() < 1)
			{
				std::cout << "No contact in the phone book. ";
				std::cout << "Add a contact first." << std::endl;
			}
			else
			{
				std::cout << "Type in the index of contact: ";
				while (!(std::cin >> index) || index < 0 || index >= phonebook.getNbContacts())
				{
					if (std::cin.eof())
						return (1);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << index << " is not recognized" << std::endl;
					phonebook.printPhonebook();
					std::cout << "Type in the index of contact: ";
				}
				phonebook.searchContact(index);
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			
		}
		else if (!action.compare("EXIT") || !action.compare("exit"))
			exit = true;
	}
}
