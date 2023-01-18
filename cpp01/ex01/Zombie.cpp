/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:12:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 09:02:26 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie default constructor for: " << this->_name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor for: " << this->_name << std::endl;
}

Zombie::Zombie(std::string name) :
_name(name)
{
	std::cout << "Zombie constructor for: " << this->_name << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
