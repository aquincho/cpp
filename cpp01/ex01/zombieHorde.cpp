/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:42:12 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 09:03:11 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombie;

	std::cout << "Creation: " << N << " Zombies" << std::endl;
	try
	{
		zombie = new Zombie[N];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	std::cout << "Initialization: " << N << " Zombies" << std::endl;
	for (int i = 0; i < N; i++)
	{
		
		zombie[i].setName(name);
		std::cout << "zombie #" << i << " named: " << zombie[i].getName() << std::endl;
	}
	return (zombie);
}