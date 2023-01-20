/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:20 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 16:18:29 by aquincho         ###   ########.fr       */
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

	Fixed &operator=(Fixed const &copy);
	Fixed &operator+(Fixed const &val);
	Fixed &operator-(Fixed const &val);
	Fixed &operator*(Fixed const &val);
	Fixed &operator/(Fixed const &val);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed	max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &a);