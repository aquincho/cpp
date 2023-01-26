/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:58:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 11:17:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat &src)
{
	std::cout << "Cat assign operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meooowww" << std::endl;
}