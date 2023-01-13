/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:12:15 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/12 10:10:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
	int			_index;
	std::string _fields[5];
	std::string	_fieldNames[5];

public:
	Contact();
	~Contact();

	void	setContact(int index);
	void	printContact() const;
	void	printShort(void) const;
};

#endif