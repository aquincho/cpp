/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:31:32 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/09 13:14:24 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{

	Array<int> *tabInt0 = new Array<int>();
	Array<int> tabInt10(10);
	Array<int>	tabIntNeg(-2);
	Array<char>	tabChar(26);
	Array<std::string>	tabStr(5);
	
	std::cout << tabInt0 << " " << tabInt0->getSize() << " ";
	std::cout << tabInt0->getIndexValue(0)  << std::endl;
	for (int i = 0; i < 10; i++)
		tabInt10.setIndexValue(i, i * 2);
	std::cout << "taile: " << tabInt10.getSize() << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << tabInt10.getIndexValue(i) << " ";
	std::cout << std::endl;
	for (int i = 0; i < 26; i++)
		tabChar.setIndexValue(i, 'a' + i);
	std::cout << "taile: " << tabChar.getSize() << std::endl;
	for (int i = 0; i < 26; i++)
		std::cout << tabChar.getIndexValue(i) << " ";
	std::cout << std::endl;
	tabStr.setIndexValue(0, "Hello, ");
	tabStr.setIndexValue(1, "it ");
	tabStr.setIndexValue(2, "is ");
	tabStr.setIndexValue(3, "snowing ");
	tabStr.setIndexValue(4, "out there");
	std::cout << tabStr;
	std::cout << "taile: " << tabStr.getSize() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << tabStr.getIndexValue(i);
	std::cout << std::endl;
	std::cout << tabIntNeg.getSize() <<  std::endl;
	delete tabInt0;
	return (0);
}