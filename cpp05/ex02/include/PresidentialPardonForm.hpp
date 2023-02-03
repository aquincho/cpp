/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:22:09 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 09:31:57 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);

	std::string		getTarget(void) const;
	virtual void	doAction(void) const;
};

#endif