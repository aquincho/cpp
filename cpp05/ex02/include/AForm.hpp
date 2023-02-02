/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:58:25 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 13:33:41 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	int					_signatureGrade;
	int					_executionGrade;
	AForm(void);

public:
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &src);
	virtual ~AForm(void);

	AForm	&operator=(const AForm &src);

	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSignatureGrade(void) const;
	int				getExectutionGrade(void) const;
	void			beSigned(Bureaucrat &brt);
	virtual void	doAction(void) const = 0;
	void			execute(Bureaucrat const & executor) const;
	

	class GradeTooHighException : public std::exception
	{public: virtual const char* what() const throw();	};
	class GradeTooLowException : public std::exception
	{public: virtual const char* what() const throw();	};
	class FormNotSignedException : public std::exception
	{public: virtual const char* what() const throw();	};
	
};

std::ostream&	operator<<(std::ostream& os, AForm& frm);

#endif