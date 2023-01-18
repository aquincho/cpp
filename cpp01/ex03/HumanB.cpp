/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:25:23 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 09:39:49 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << this->_name << " created with no weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " whith " << this->_weapon->getType();
	std::cout << " destructed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks whith their " << this->_weapon->getType();
	std::cout << std::endl;
}