/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:31 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/01 09:53:29 by aquincho         ###   ########.fr       */
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
		if (this->_item[i])
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
	if (idx < 0 || idx >= 4)
		return ;
	delete this->_item[idx];
	this->_nbItems--;
	for (int i = idx; i < (this->_nbItems - idx); i++)
	{
		this->_item[i] = this->_item[i + 1]->clone();
		delete this->_item[i + 1];
	}
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_nbItems)
		return ;
	this->_item[idx]->use(target);
}

void				Character::listItems(void) const
{
	std::cout << "items of " << this->getName() << std::endl;
	for (int i = 0; i < this->_nbItems; i++)
		std::cout << this->_item[i]->getType() << std::endl;
}