/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:59:23 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/01 09:43:19 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	*this = src;
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure &src)
{
	if (this != &src)
		this->_type.assign(src.getType());
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
	std::cout << std::endl;
}
