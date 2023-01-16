/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:57 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/16 13:29:15 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1;
	
	std::cout << "creation d'un zombie sur la heap" << std::endl;
	zombie1 = newZombie("George A");
	std::cout << "presentation du zombie sur la heap" << std::endl;
	zombie1->announce();
	std::cout << "destruction du zombie sur la heap" << std::endl;
	delete zombie1;
	std::cout << "Utilisation d'un sombie sur la stack" << std::endl;
	randomChump("Zack");
	return (0);
}