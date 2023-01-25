/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:40:36 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 15:31:51 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	diam("Goldie");
	
	diam.whoAmI();
	diam.energyLeft();
	diam.attack("Lucifer");
	diam.energyLeft();
	diam.takeDamage(20);
	diam.energyLeft();
	diam.HighFivesGuys();
	diam.guardGate();
	diam.energyLeft();
	return (0);
}
