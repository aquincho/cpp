/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:06:44 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/10 10:17:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>

int	main(void)
{
	std::vector<int>	v;
	std::list<int>		li;

	for (int i = 0; i < 20; i++)
		v.push_back(i * 2);
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try
	{
		//::easyfind(v, 8);
		std::cout << "find 8: " << *::easyfind(v, 8) << " Value is found" << std::endl;
		//::easyfind(v, 11);
		std::cout << "find 11: " << *::easyfind(v, 11) << " Value is found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "List: ";
	for (int i = 0; i < 20; i++)
		li.push_back(i * 2);
	for (std::list<int>::iterator it = li.begin(); it != li.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try
	{
		//::easyfind(v, 8);
		std::cout << "find 8: " << *::easyfind(li, 8) << " Value is found" << std::endl;
		//::easyfind(v, 11);
		std::cout << "find 11: " << *::easyfind(li, 11) << " Value is found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}