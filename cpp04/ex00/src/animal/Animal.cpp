/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 12:09:43 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->_type.assign(src._type);
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called with: " << type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal &src)
{
	
	std::cout << "Animal assign operator called" << std::endl;
	if (this != &src)
	{
		this->_type.assign(src.getType());
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void		Animal::setType(std::string type)
{
	this->_type = type;
}

void		Animal::makeSound(void) const
{
}