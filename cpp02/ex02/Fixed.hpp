/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:20 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 12:31:03 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &copy);
	~Fixed(void);
	Fixed(const int value);
	Fixed(const float value);

	Fixed	&operator=(Fixed const &copy);
	
	bool	operator>(Fixed const &operand);
	bool	operator<(Fixed const &operand);
	bool	operator>=(Fixed const &operand);
	bool	operator<=(Fixed const &operand);
	bool	operator==(Fixed const &operand);
	bool	operator!=(Fixed const &operand);

	Fixed	operator+(Fixed const &operand);
	Fixed	operator-(Fixed const &operand);
	Fixed	operator*(Fixed const &operand);
	Fixed	operator/(Fixed const &operand);

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed	min(Fixed const &a, Fixed const &b);
	static Fixed	max(Fixed const &a, Fixed const &b);
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &a);