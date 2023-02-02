/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:58:25 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 10:03:38 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	int					_signatureGrade;
	int					_executionGrade;
public:
	Form(void);
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &src);
	virtual ~Form(void);

	Form	&operator=(const Form &src);

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getSignatureGrade(void) const;
	int			getExectutionGrade(void) const;
	void		beSigned(Bureaucrat &brt);

	class GradeTooHighException : public std::exception
	{public: virtual const char* what() const throw();	};
	class GradeTooLowException : public std::exception
	{public: virtual const char* what() const throw();	};
	
};

std::ostream&	operator<<(std::ostream& os, Form& frm);

#endif