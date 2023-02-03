/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:48:54 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 14:16:20 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("", 1, 150)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
AForm(src), _target(src.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->AForm::operator=(src);
	this->_target.assign(src.getTarget());
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::doAction(void) const
{
	std::cout << "Shruberrys has been planted" << std::endl;
	std::ofstream	treeFile;
	
	try
	{
		treeFile.open((this->getTarget() + "_shrubbery").c_str(),
		std::ofstream::out | std::ofstream::trunc);
		if (!treeFile.is_open() || treeFile.bad())
			throw ShrubberyCreationForm::FileTreeException();
		else
		{
			treeFile << TREE << "\n" << TREE << "\n" << TREE << std::endl;
			treeFile.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char*	ShrubberyCreationForm::FileTreeException::what() const throw()
{
	return ("File Creation problem");
}