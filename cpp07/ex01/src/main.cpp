/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:27 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/09 09:26:28 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	ft_add(int& n)
{
	n *= 2;
}


void	ft_toupper(char& c)
{
	c = std::toupper(static_cast<char>(c));
}

int main()
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char	str[] = {'a', 'b', 'c', 'd'};

	::iter(tab, 10, ft_add);
	for (int i = 1; i < 10; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
	::iter(str, 4, ft_toupper);
	for (int i = 1; i < 4; i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;
}