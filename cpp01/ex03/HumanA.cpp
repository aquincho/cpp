/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:14 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 09:49:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
_name(name), _weapon(weapon)
{
	std::cout << this->_name << " whith " << this->_weapon.getType();
	std::cout << " created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " whith " << this->_weapon.getType();
	std::cout << " destructed" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks whith their " << this->_weapon.getType();
	std::cout << std::endl;
}
