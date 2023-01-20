/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:20 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 13:45:39 by aquincho         ###   ########.fr       */
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
	Fixed &operator=(Fixed const &copy);
	
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};
