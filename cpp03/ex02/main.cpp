/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:40:36 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 14:11:21 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	clap1("Morpheus");
	FragTrap	scav1("Mervyn");
	FragTrap	scav2("Gregory");
	

	scav1.energyLeft();
	scav1.HighFivesGuys();
	scav1.energyLeft();
	scav1.attack("Despair");
	scav1.energyLeft();
	scav1.takeDamage(50);
	scav1.energyLeft();
	scav1.beRepaired(20);
	scav1.energyLeft();
	scav1.attack("Desire");
	scav1.energyLeft();
	scav1.takeDamage(90);
	scav1.energyLeft();
	scav1.beRepaired(50);
	scav1.energyLeft();
	scav1.attack("Destiny");
	scav1.energyLeft();
	scav1.HighFivesGuys();
	scav1.energyLeft();
	std::cout << std::endl;
	scav2.energyLeft();
	scav2.takeDamage(99);
	scav2.energyLeft();
	scav2.HighFivesGuys();
	scav2.energyLeft();
	for(int i = 0; i <= 100; i++)
		scav2.beRepaired(1);
	scav2.energyLeft();
	scav2.attack("Destiny");
	scav2.energyLeft();
	scav2.HighFivesGuys();
	scav2.energyLeft();
	return (0);
}
