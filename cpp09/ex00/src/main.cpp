/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:21:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/12 11:59:24 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ifstre		buff;
	
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (0);
	}
	BitcoinExchange*	btc = new BitcoinExchange();
	//btc->printData();
	float result;
	std::cout << btc->getSize() << " - " << btc->getStatus() << std::endl;
	try
	{
		ifs.open(std::string(argv[1]), std::ifstream::in);
		std::getline(ifs, buff);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	(void)argv;
}