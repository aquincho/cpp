/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:48:05 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 08:49:54 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define NB_CONTACTS 8

class PhoneBook
{
private:
	Contact	_contacts[NB_CONTACTS];
	int		_nbContacts;
	int		_indexLastEntry;

public:
	PhoneBook();
	~PhoneBook();

	int		getNbContacts(void) const;
	void	printActions(void) const;
	void	printPhonebook(void) const;
	void	addContact(void);
	void	searchContact(int index) const;
};

#endif