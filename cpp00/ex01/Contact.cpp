/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:44:57 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/12 11:43:34 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::string	fn[5] = {"first name", "last name", "nickname",
		"phone number", "darkest secret"};
	for (int i = 0; i < 5; i++)
		this->_fieldNames[i] = fn[i];
}

Contact::~Contact()
{
}

void	Contact::setContact(int index)
{
	this->_index = index;
	std::cout << "Type in informations for contact # " << this->_index
		<< std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Type in contact's " << this->_fieldNames[i] << ": ";
		std::getline (std::cin, this->_fields[i]);
		while(this->_fields[i].empty())
		{
			std::cout << "This information cannot be empty" << std::endl;
			std::cout << "Type in contact's " << this->_fieldNames[i] << ": ";
			std::getline (std::cin, this->_fields[i]);
		}
	}
}

void	Contact::printShort(void) const
{
	std::string	tmp;

	std::cout << std::setw(10);
	std::cout << this->_index << "|";
	for (int i = 0; i < 3; i++)
	{
		if (this->_fields[i].size() <= 10)
			tmp.append(this->_fields[i]);
		else
		{
			tmp.append(this->_fields[i].substr(0, 9));
			tmp.append(".");
		}
		std::cout << std::setw(10);
		std::cout << tmp << "|";
		tmp.clear();
	}
	std::cout << std::endl;
}

void	Contact::printContact() const
{
	for(int i = 0; i < 5; i++)
		std::cout << this->_fieldNames[i] << ": " << this->_fields[i] << std::endl;
}