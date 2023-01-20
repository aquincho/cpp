/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 10:12:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "strReplace.hpp"

int	main(int argc, char **argv)
{
	strReplace	inFile;

	if (argc != 4)
	{
		std::cout << "incorrect number of arguments" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "arguments cannot be empty" << std::endl;
		return (1);
	}
	if (inFile.open(argv[1]))
		return (1);
	inFile.replace(argv[2], argv[3]);
	inFile.close();
	return (0);
}