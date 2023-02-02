/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:03:37 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 10:00:51 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form	f0("42 alinea 12", 1, 150);
		std::cout << f0;
		Form	f0bis("42 alina 13", 0, 100);
		std::cout << f0bis;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create form. " << e.what() << '\n';
	}
	
	try
	{
		Form	f0ter("42 alinea 14", 1, 151);
		std::cout << f0ter;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create form. " << e.what() << '\n';
	}
	
	
	try
	{
		Bureaucrat	b1("jojo", 42);
		Form		f1("alinea1", 50, 100);
		Form		f2("alinea2", 10, 100);

		std::cout << "b1:" << b1;
		std::cout << "f1:" << f1;
		std::cout << "f2:" << f2;
		b1.signForm(f1);
		b1.signForm(f2);
		std::cout << "f1:" << f1;
		std::cout << "f2:" << f2;
	}catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}