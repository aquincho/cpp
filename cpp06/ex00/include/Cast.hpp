/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:04:16 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/06 09:03:19 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
# define CAST_HPP

#include <iostream>
# include <string>
# include <sstream>

# define IMAX	2147483647
# define IMIN	-2147483648
# define FMAX	3.402823e+38
# define FMIN	1.175494e-38

typedef enum e_type
{
	_char,
	_int,
	_float,
	_double,
	_other
}	t_type;

class Cast
{
private:
	std::string	_value;
	t_type		_type;
	int			_intValue;
	float		_floatValue;
	double		_doubleValue;
	int			_precision;
public:
	Cast(void);
	Cast(char *arg);
	Cast(const Cast &src);
	~Cast();

	Cast	&operator=(const Cast &src);

	std::string	getValue(void) const;
	t_type		getType(void) const;
	int			getIntValue(void) const;
	float		getFloatValue(void) const;
	double		getDoubleValue(void) const;
	int			getPrecision(void) const;
	void		setPrecision(void);
	t_type		getValueType(void);
	char		toChar(void) const;
	int			toInt(void) const;
	float		toFloat(void) const;
	double		toDouble(void) const;

	class NotDisplayableException : public std::exception
	{public: virtual const char * what() const throw();};
	class ImpossibleException : public std::exception
	{public: virtual const char* what() const throw();};
	class NanException : public std::exception
	{public: virtual const char* what() const throw();};
};

std::ostream&	operator<<(std::ostream& os, Cast &src);

#endif

