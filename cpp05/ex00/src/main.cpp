/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:03:37 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/01 11:45:52 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	b1("jojo", 42);

		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		b1.getName();
		std::cout << b1;
		std::cout << b1.getName() << " va monter de 12 echelons:" << std::endl;
		b1.gradeIncrease(12);
		std::cout << b1;
		std::cout << b1.getName() << " va baisser de 10 echelons:" << std::endl;
		b1.gradeDecrease(10);
		std::cout << b1;
		std::cout << b1.getName() << " va monter de 100 echelons:" << std::endl;
		b1.gradeIncrease(100);
		std::cout << b1;
	}catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b2("jojo trop haut", 0);

		b2.getGrade();
		b2.getName();
		std::cout << b2;		
	}catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b3("jojo trop haut", 151);

		b3.getGrade();
		b3.getName();
		std::cout << b3;		
	}catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}