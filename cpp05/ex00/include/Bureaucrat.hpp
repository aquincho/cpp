/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:02:43 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/01 11:37:59 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &src);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		gradeIncrease(int amount);
		void		gradeDecrease(int amount);

		class	GradeTooHighException : public std::exception
		{public: virtual const char * what() const throw();};
		class	GradeTooLowException : public std::exception
		{public: virtual const char * what() const throw();};
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& brt);

#endif