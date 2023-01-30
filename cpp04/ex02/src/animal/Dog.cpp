/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:05 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 11:45:55 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "copy Dog constructor called" << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, src._brain->getIdea(i));
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "Dog assign operator called" << std::endl;
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

std::string	Dog::getIdea(const int i) const
{
	return (this->_brain->getIdea(i));
}

void		Dog::setIdea(const int i, const std::string idea)
{
	this->_brain->setIdea(i, idea);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF" << std::endl;
}