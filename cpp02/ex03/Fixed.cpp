/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:35 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 13:09:31 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(const int value)
{
	this->_value = value << Fixed::_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << Fixed::_bits));
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(Fixed const &copy)
{
	this->_value = copy.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &operand)
{
	return (this->getRawBits() > operand.getRawBits());
}

bool	Fixed::operator<(Fixed const &operand)
{
	return (this->getRawBits() < operand.getRawBits());
}

bool	Fixed::operator>=(Fixed const &operand)
{
	return (this->getRawBits() >= operand.getRawBits());
}

bool	Fixed::operator<=(Fixed const &operand)
{
	return (this->getRawBits() <= operand.getRawBits());
}

bool	Fixed::operator==(Fixed const &operand)
{
	return (this->getRawBits() == operand.getRawBits());
}

bool	Fixed::operator!=(Fixed const &operand)
{
	return (this->getRawBits() != operand.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &operand)
{
	Fixed	result(*this);

	result.setRawBits(this->getRawBits() + operand.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &operand)
{
	Fixed	result(*this);

	result.setRawBits(this->getRawBits() - operand.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &operand)
{
	Fixed	result(*this);

	result.setRawBits((this->getRawBits() * operand.getRawBits()) / (1 << Fixed::_bits));
	return (result);
}

Fixed	Fixed::operator/(Fixed const &operand)
{
	Fixed	result(*this);

	result.setRawBits((this->getRawBits() * (1 << Fixed::_bits)) / operand.getRawBits());
	return (result);
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	int	result;

	result = this->_value >> Fixed::_bits;
	return(result);
}

float	Fixed::toFloat(void) const
{
	float	result;
	
	result = (float)this->_value / (float)(1 << Fixed::_bits);
	return (result);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	else
		return (a);
}

Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	Fixed	tmp;

	if (a.getRawBits() > b.getRawBits())
		tmp = b;
	else
		tmp = a;
	return (tmp);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	Fixed	tmp;

	if (a.getRawBits() > b.getRawBits())
		tmp = a;
	else
		tmp = b;
	return (tmp);
}

std::ostream& operator<<(std::ostream &out, Fixed const &a)
{
	out << a.toFloat();
	return (out);
}