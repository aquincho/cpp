/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:58:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 11:44:07 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <ostream>

Cat::Cat() : Animal("cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	if (this->_brain)
		delete (_brain);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, src._brain->getIdea(i));
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat &src)
{
	std::cout << "Cat assign operator called" << std::endl;
	if (this != &src)
	{
		this->_type.assign(src._type);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, src._brain->getIdea(i));
	}
	return (*this);
}


std::string	Cat::getIdea(const int i) const
{
	return (this->_brain->getIdea(i));
}

void		Cat::setIdea(const int i, const std::string idea)
{
	this->_brain->setIdea(i, idea);
}

void		Cat::makeSound(void) const
{
	std::cout << "Meooowww" << std::endl;
}