/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:06:37 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 11:34:59 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name(""), _signed(false), _signatureGrade(1), _executionGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) :
_name(name), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_signatureGrade = signGrade;
		this->_executionGrade = execGrade;
	}
}

AForm::AForm(const AForm &src)
{
	*this = src;
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_signed = src.getSigned();
		this->_signatureGrade = src.getSignatureGrade();
		this->_executionGrade = src.getExectutionGrade();
	}
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSigned(void) const
{
	return (this->_signed);
}

int			AForm::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

int			AForm::getExectutionGrade(void) const
{
	return (this->_executionGrade);
}

void		AForm::beSigned(Bureaucrat &brt)
{
	if (brt.getGrade() <= this->getSignatureGrade())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExectutionGrade())
		throw AForm::GradeTooLowException();
	else
		this->doAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream&	operator<<(std::ostream& os, AForm& frm)
{
	os << "Form name: " << frm.getName() << ", signed?: " << frm.getSigned();
	os << ", Grade to sign: " << frm.getSignatureGrade();
	os << ", Grade to execute: " << frm.getExectutionGrade() << std::endl;
	return (os);
}
