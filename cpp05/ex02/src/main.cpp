/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:03:37 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 09:47:43 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat				b0("Bob", 3);
		Bureaucrat				b1("Jim", 130);
		Bureaucrat				b2("Alfred", 146);
		Bureaucrat				b3("Bill", 150);
		ShrubberyCreationForm	f0("jardin");
		ShrubberyCreationForm	f1("parc");

		std::cout << f0;
		std::cout << b0;
		std::cout << b1;
		b0.signForm(f0);
		b1.executeForm(f0);
		b2.signForm(f1);
		b3.executeForm(f1);
		b0.signForm(f1);
		b3.executeForm(f1);
		b1.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create form. " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat				b4("Bob", 3);
		Bureaucrat				b5("Jim", 48);
		Bureaucrat				b6("Alfred", 146);
		RobotomyRequestForm		f2("toto");
		RobotomyRequestForm		f3("titi");
		RobotomyRequestForm		f4("tata");
		RobotomyRequestForm		f5("tutu");

		std::cout << f2;
		std::cout << f3;
		b4.signForm(f2);
		b5.executeForm(f2);
		b4.executeForm(f2);
		b5.signForm(f3);
		b4.executeForm(f3);
		b6.signForm(f4);
		b4.executeForm(f4);
		b4.signForm(f5);
		b4.executeForm(f5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create form. " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat				b7("Bob", 3);
		Bureaucrat				b8("Jim", 23);
		Bureaucrat				b9("Alfred", 146);
		PresidentialPardonForm	f7("Arthur");
		PresidentialPardonForm	f8("Marvin");

		std::cout << f7;
		std::cout << f8;
		b8.signForm(f7);
		b7.executeForm(f7);
		b9.signForm(f8);
		b7.executeForm(f8);
		b8.signForm(f8);
		b9.executeForm(f8);
		b7.executeForm(f8);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create form. " << e.what() << '\n';
	}
}
