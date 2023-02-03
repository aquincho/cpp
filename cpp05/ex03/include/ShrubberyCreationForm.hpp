/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:42:57 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 14:15:27 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define TREE "      #\n     ###\n    #####\n   #######\n  #########\n      #\n      #\n"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);

	std::string		getTarget(void) const;
	virtual void	doAction(void) const;

	class FileTreeException : public std::exception
	{public: virtual const char* what() const throw();	};
};

#endif