/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 16:24:42 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = copy;
}

Animal::Animal(std::string type) : _type(type)
{
	
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal &copy)
{
	
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void		Animal::makeSound(void) const
{
}