/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:18:16 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 15:28:19 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
_name(""), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "ClapTrap constructor with name called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignment operator called for " << copy._name << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void	ClapTrap::energyLeft(void) const
{
	std::cout << this->_name << std::endl;
	std:: cout << "\tEnergy: " << this->_energyPoints;
	std:: cout << "\tHit points: " << this->_hitPoints << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::attack(const std::string& name)
{
	std::cout << "ClapTrap " << this->_name;
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << " attacks " << name << ", causing ";
		std::cout << this->_attackDamage << " points of damage!";
	}
	else if (this->_energyPoints > 0)
		std::cout << " has not enough hit points to attak!";
	else
		std::cout << " has not enough energy points to attak!";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < this->_hitPoints)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " has taken ";
	std::cout << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name;
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout <<" has been repaired with ";
		std::cout << amount << " hit points.";
	}
	else if (this->_energyPoints > 0)
		std::cout << " has not enough hit points to be reapaired!";
	else
		std::cout << " has not enough energy points to be reapaired!";
	std::cout << std::endl;
}
