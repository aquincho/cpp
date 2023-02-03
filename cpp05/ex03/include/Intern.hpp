/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:55:06 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 11:09:28 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	static AForm*	sRCreate(std::string target);
	static AForm*	rRCreate(std::string target);
	static AForm*	pPCreate(std::string target);
public:
	Intern(void);
	Intern(const Intern &src);
	~Intern();

	Intern	&operator=(const Intern &src);

	AForm*	makeForm(std::string name, std::string target);

	class	UnknownFormName : public std::exception
	{public: virtual const char * what() const throw();};
};

#endif