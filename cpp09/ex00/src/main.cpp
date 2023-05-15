/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:21:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/15 13:24:32 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	BitcoinExchange	btc;
	
	if (!btc.getStatus())
			return (0);
	if (argc != 2)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return (0);
	}
	
	try
	{
		ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		ifs.open(argv[1], std::ifstream::in);
	}
	catch(std::ifstream::failure& e)
	{
		std::cerr << "Error: could not open file: " << argv[1] << "\n";
		return (0);
	}
	
		std::cout << "data loaded: " << btc.getSize() << " - " << btc.getStatus() << std::endl;
	try
	{
		std::string	line;
		
		while (!ifs.eof())
		{
			std::getline(ifs, line);
			if (!line.empty() && !line.compare("date | value"))
				continue;
			else if (!line.empty())
				btc.resolveValue(std::string(line));
		}
		ifs.close();
	}
	catch(std::ifstream::failure& e)
	{
		ifs.close();
		return (0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	
}
