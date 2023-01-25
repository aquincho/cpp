/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:35:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 15:25:37 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :
ClapTrap(copy), FragTrap(), ScavTrap()
{
	*this = copy;
}

DiamondTrap::DiamondTrap(std::string name) :
ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name: " << this->_name;
	std::cout << "\tmy ClapTrap name: " << ClapTrap::_name << std::endl;
}