/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:40:49 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/12 10:49:18 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nbContacts(0), _indexLastEntry(0)
{
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::getNbContacts() const
{
	return (this->_nbContacts);
}

void	PhoneBook::printActions(void) const
{
	std::cout << "Please type in:" << std::endl;
	std::cout << "ADD - to add a new contact," << std::endl;
	std::cout << "SEARCH - to show contact details," << std::endl;
	std::cout << "EXIT - to quit." << std::endl;
}

void	PhoneBook::addContact(void)
{
	if (this->_nbContacts > 0)
		this->_indexLastEntry = (this->_indexLastEntry + 1) % NB_CONTACTS;
	if (this->_nbContacts < NB_CONTACTS)
		this->_nbContacts++;
	std::cout << "contact index:" << this->_indexLastEntry << std::endl;
	this->_contacts[this->_indexLastEntry].setContact(this->_indexLastEntry);
}

void	PhoneBook::printPhonebook(void)
{
	std::cout << this->_nbContacts << " contacts in phone book" << std::endl;
	for (int i = 0; i < this->_nbContacts; i++)
		this->_contacts[i].printShort();
}

void	PhoneBook::searchContact(int index)
{
	this->_contacts[index].printContact();
}
