/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:59:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 11:31:38 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(void)
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

AForm*	Intern::sRCreate(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::rRCreate(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::pPCreate(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] =
		{"Shrubbery Creation Form", "Robotomy Request Form",
			"Presidential Pardon Form"};
	AForm* (*formCreate[])(std::string) = {&(Intern::sRCreate), &Intern::rRCreate, &Intern::pPCreate};
		
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(formNames[i]))
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formCreate[i](target));
		}
	}
	throw Intern::UnknownFormName();
}

const char*	Intern::UnknownFormName::what() const throw()
{
	return ("Form doesn't exist");
}