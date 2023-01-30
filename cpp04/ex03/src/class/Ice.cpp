/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:49:47 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 14:43:53 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
}


Ice::Ice(const Ice &src) : AMateria(src)
{
	*this = src;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice &src)
{
	if (this != &src)
		this->_type.assign(src.getType());
	return (*this);
}

AMateria*	Ice::clone() const
{
	return(new Ice());
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << std::endl;
}
