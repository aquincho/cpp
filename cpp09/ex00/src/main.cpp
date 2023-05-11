/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:21:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/11 12:51:44 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (0);
	}
	BitcoinExchange*	btc = new BitcoinExchange();
	std::cout << btc->getSize() << std::endl;
	//btc->printData();
	std::cout << btc->getStatus() << std::endl;
	(void)argv;
}