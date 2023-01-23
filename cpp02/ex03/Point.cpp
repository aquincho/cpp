/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:37:51 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 14:57:39 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) :
_x(x), _y(y)
{
}

Point::Point(Point const &copy) :
_x(copy._x), _y(copy._y)
{
}

Point::~Point()
{
}

Point	&Point::operator=(Point const &copy)
{
	Point tmp(copy._x.toFloat(), copy._y.toFloat());
	(*this) = tmp;
	
	return (*this);
}

Fixed	Point::getX(void)
{
	return (this->_x);
}

Fixed	Point::getY(void)
{
	return (this->_y);
}

Fixed	Point::getCoord(char c) const
{
	switch (c)
	{
	case 'x':
		return (this->_x);
		break;
	case 'y':
		return (this->_y);
		break;
	default:
		break;
	}
	return (0);
}

void	Point::printCoord(void)
{
	std::cout << "Point: " << std::endl;
	std::cout << "x: " << this->_x.toFloat();
	std::cout << " y: " << this->_y.toFloat();
	std::cout <<std::endl;
}