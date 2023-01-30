/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:06:50 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 14:53:57 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource(),
_nbLearned(0), _materiaLearned(NULL)
{
	this->_materiaLearned = new AMateria*;
	this->_materiaLearned[0] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) :
IMateriaSource(src), _nbLearned(src._nbLearned)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		this->_nbLearned = src._nbLearned;
		for (int i = 0; i < src._nbLearned; i++)
			this->_materiaLearned[i] = src._materiaLearned[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	this->_materiaLearned[_nbLearned] = materia->clone();
	this->_nbLearned++;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_nbLearned; i++)
	{
		if (this->_materiaLearned[i]->getType().compare(type) == 0)
			return (_materiaLearned[i]->clone());
	}
	return (NULL);
}
