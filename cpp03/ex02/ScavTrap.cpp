/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:18:00 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 13:33:33 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
	*this = copy;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called with name: " << this->_name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name;
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << " is in gate keeper mode!" << std::endl;
	}
	else if (this->_energyPoints > 0)
		std::cout << " has not enough hit points to get in gate keeper mode!";
	else
		std::cout << " has not enough energy points to get in gate keeper mode!";
	std::cout << std::endl;
}