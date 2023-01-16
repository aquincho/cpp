/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:57 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/16 14:32:25 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	Zombie	*zombies;
	int		zombieCount;
	
	if (argc != 2)
		zombieCount = 3;
	else
		zombieCount = std::atoi(argv[1]);
	zombies = zombieHorde(zombieCount, "George A");
	for (int i = 0; i < zombieCount; i++)
		zombies[i].announce();
	std::cout << "Destruction:" << std::endl;
	delete[] zombies;
	return (0);
}