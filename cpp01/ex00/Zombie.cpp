/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:12:02 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 08:53:26 by aquincho         ###   ########.fr       */
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
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::get_name(void) const
{
	return (this->_name);
}
