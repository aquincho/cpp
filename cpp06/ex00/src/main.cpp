/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:43:41 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 14:40:34 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments";
		return (0);
	}
	
	try
	{
		Cast	cast(argv[1]);
		std::cout << cast;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}