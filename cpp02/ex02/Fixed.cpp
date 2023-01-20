/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:35 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 16:17:42 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy construcor called" << std::endl;
	//this->_value = copy._value;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * pow(2, this->_bits));
}

Fixed& Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy._value;
	return (*this);
}

Fixed& Fixed::operator+(Fixed const &val)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + val.getRawBits());
	return (result);
}

Fixed& Fixed::operator-(Fixed const &val)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - val.getRawBits());
	return (result);
}

Fixed& Fixed::operator*(Fixed const &val)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() * val.getRawBits());
	return (result);
}

Fixed& Fixed::operator/(Fixed const &val)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() / val.getRawBits());
	return (result);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	int	result;

	result = this->_value >> this->_bits;
	return(result);
}

float	Fixed::toFloat(void) const
{
	float	result;
	
	result = (float)this->_value / std::pow(2, this->_bits);
	return (result);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream &out, Fixed const &a)
{
	out << a.toFloat();
	return (out);
}