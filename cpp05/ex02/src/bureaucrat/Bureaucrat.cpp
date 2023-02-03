/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:04:07 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 09:16:52 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) :
_name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void		Bureaucrat::gradeIncrease(int amount)
{
	if ((this->_grade - amount) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= amount;
}

void		Bureaucrat::gradeDecrease(int amount)
{
	if ((this->_grade + amount) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade -= amount;
}

void		Bureaucrat::signForm(AForm &frm)
{
	try
	{
		frm.beSigned(*this);
		std::cout << this->getName() << " signed " << frm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << frm.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm &frm)
{
	try
	{
		frm.execute(*this);
		std::cout << this->getName() << " executed " << frm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << frm.getName();
		std::cerr << " because: " << e.what() << std::endl;
	}
	
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is to low");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& brt)
{
	os << brt.getName() << ", bureaucrat grade " << brt.getGrade() << std::endl;
	return (os);
}
