/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 09:38:10 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	//*this = src;
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
		this->_type = src._type;
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

std::string	Animal::getIdea(const int i) const
{
	(void)i;
	return ("");
}

void		Animal::setIdea(const int i, const std::string idea)
{
	(void)i;
	(void)idea;
}

void		Animal::makeSound(void) const
{
}