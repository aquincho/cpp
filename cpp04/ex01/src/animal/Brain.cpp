/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:48:10 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 11:43:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain construcor called" << std::endl;
	this->setFirstIdeas();
}

Brain::Brain(const Brain &src)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i].assign(src._ideas[i]);
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
			this->_ideas[i].assign(src._ideas[i]);
	return (*this);
}

std::string	Brain::getIdea(const int i) const
{
	return (this->_ideas[i]);
}

void		Brain::setIdea(const int i, const std::string idea)
{
	this->_ideas[i].assign(idea);
}

void		Brain::setFirstIdeas(void)
{
	for (int i = 0; i < 100; i++)
		this->setIdea(i, "idea " + ft_iToStr(i));
}

std::string	ft_iToStr(int i)
{
	std::ostringstream	tmp;
	tmp << i;
	return (tmp.str());
}