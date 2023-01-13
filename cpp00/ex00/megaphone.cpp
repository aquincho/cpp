/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:53:37 by aquincho          #+#    #+#             */
/*   Updated: 2022/12/30 09:43:48 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string	str(argv[i]);
		for (unsigned long j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str.at(j));
	}
	std::cout << std::endl;
	return (0);
}
