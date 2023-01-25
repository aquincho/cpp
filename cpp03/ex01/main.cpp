/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:40:36 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 13:27:28 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	clap1("Morpheus");
	ScavTrap	scav1("Gregory");
	ScavTrap	scav2("Mervyn");
	

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
	scav1.guardGate();
	scav1.energyLeft();
	std::cout << std::endl;
	scav2.energyLeft();
	scav2.takeDamage(99);
	scav2.energyLeft();
	scav2.guardGate();
	scav2.energyLeft();
	for(int i = 0; i <= 50; i++)
		scav2.beRepaired(1);
	scav2.energyLeft();
	scav2.attack("Destiny");
	scav2.energyLeft();
	scav2.guardGate();
	scav2.energyLeft();
	return (0);
}
