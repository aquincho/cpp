/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:06:37 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 10:09:11 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _signed(false), _signatureGrade(1), _executionGrade(150)
{
}

Form::Form(std::string name, int signGrade, int execGrade) :
_name(name), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else
	{
		this->_signatureGrade = signGrade;
		this->_executionGrade = execGrade;
	}
}

Form::Form(const Form &src)
{
	*this = src;
}

Form::~Form()
{
}

Form&	Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_signed = src.getSigned();
		this->_signatureGrade = src.getSignatureGrade();
		this->_executionGrade = src.getExectutionGrade();
	}
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_signed);
}

int			Form::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

int			Form::getExectutionGrade(void) const
{
	return (this->_executionGrade);
}

void		Form::beSigned(Bureaucrat &brt)
{
	if (brt.getGrade() <= this->getSignatureGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream&	operator<<(std::ostream& os, Form& frm)
{
	os << "Form name: " << frm.getName() << ", signed?: " << frm.getSigned();
	os << ", Grade to sign: " << frm.getSignatureGrade();
	os << ", Grade to execute: " << frm.getExectutionGrade() << std::endl;
	return (os);
}
