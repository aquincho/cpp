/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:48:10 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 09:41:22 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain construcor called" << std::endl;
}

Brain::Brain(const Brain &src) : _ideas(src._ideas)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	//*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain &src)
{
	std::cout << "Brain assign operator called" << std::endl;
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return (*this);
}

std::string	Brain::getIdea(const int i) const
{
	return (this->_ideas[i]);
}

void		Brain::setIdea(const int i, const std::string idea)
{
	this->_ideas[i] = idea;
}
