/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:31 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 15:24:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _nbItems(0)
{
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
}

Character::Character(std::string name) :
_name(name), _nbItems(0)
{
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
}

Character::Character(const Character &src) :
_name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._item[i])
			this->_item[i] = src._item[i]->clone();
	}
}

Character::~Character()
{
}

Character&	Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_item[i]);
			delete this->_item[i];
		if (src._item[i])
			this->_item[i] = src._item[i]->clone();
	}
	return (*this);
}

std::string	const & Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	if (this->_nbItems < 4)
	{
		this->_item[this->_nbItems] = m->clone();
		_nbItems++;
	}
}

void				Character::unequip(int idx)
{
	if (this->_nbItems > 0)
	{
		delete this->_item[this->_nbItems - 1];
		this->_item[this->_nbItems - 1] = NULL;
		this->_nbItems--;
	}
}

void				Character::use(int idx, ICharacter& target)
{
	this->_item[idx]->use(target);
}