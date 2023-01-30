/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:47:54 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 15:46:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type) :
_type(type)
{
}

AMateria::AMateria(const AMateria &src) : _type(src._type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->_type.assign(src.getType());
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return(this->_type);
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria*	AMateria::clone() const
{
	return (NULL);
}