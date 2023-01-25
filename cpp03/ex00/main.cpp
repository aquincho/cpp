/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:40:36 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 12:07:50 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap1("Morpheus");
	ClapTrap	clap2("Death");

	clap1.energyLeft();
	clap1.attack("Despair");
	clap1.takeDamage(5);
	clap1.beRepaired(2);
	clap1.attack("Desire");
	clap1.takeDamage(10);
	clap1.beRepaired(5);
	clap1.attack("Destiny");
	std::cout << std::endl;
	clap2.energyLeft();
	clap2.takeDamage(9);
	for(int i = 0; i <= 10; i++)
		clap2.beRepaired(1);
	clap2.attack("Destiny");
	return (0);
}
