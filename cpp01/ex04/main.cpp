/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 12:34:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		buffer;
	int				pos;

	if (argc != 4)
	{
		std::cout << " incorrect number of arguments" << std::endl;
		return (1);
	}
	inFile.open(argv[1], std::ifstream::in);
	outFile.open((std::string(argv[1]).append(".replace")).c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!inFile.good() || !outFile.good())
	{
		std::cout << "File name not recognized!" << std::endl;
		return (1);
	}
	while (!inFile.eof())
	{

		std::getline(inFile, buffer);
		//std::cout << buffer << std::endl;
		outFile.write(buffer.c_str(), buffer.size());
		pos = buffer.find(argv[2]);
		while (pos >= 0)
		{
			std::cout << "found" << std::endl;
			pos = buffer.find(argv[2], pos + 1);
		}
		if (!inFile.eof())
			outFile.put('\n');
	}
	inFile.close();
	outFile.close();
	return (0);
}