/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:05 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 09:41:53 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src), _brain(src._brain)
{
	std::cout << "copy Dog constructor called" << std::endl;
	//*this = src;
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
		this->_type = src._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		this->_brain = src._brain;
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

void	Dog::setType(std::string type)
{
	this->_type = type;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF" << std::endl;
}