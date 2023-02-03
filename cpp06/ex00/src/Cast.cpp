/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:06:17 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/03 16:34:49 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

Cast::Cast(void)
{
}

Cast::Cast(char *arg) : _value(std::string(arg)), _type(_other),
_intValue(0), _floatValue(0), _doubleValue(0), _precision(0)
{
	std::stringstream ss(this->getValue());
	
	this->_type = this->getValueType();
	if (this->getType() == _int)
	{
		ss >> this->_intValue;
		std::cout << ss.good() << " " << ss.fail();
		if (!ss.fail())
		{
			this->_floatValue = static_cast<float>(this->_intValue);
			this->_doubleValue = static_cast<double>(this->_intValue);
		}
		else
			this->_type = _other;
	}
	else if (this->getType() == _float)
	{
		ss >> this->_floatValue;
		if (!ss.fail())
		{
			this->_intValue = static_cast<int>(this->_floatValue);
			this->_doubleValue = static_cast<double>(this->_floatValue);
		}
		else
			this->_type = _other;
	}
	else if (this->getType() == _double)
	{
		ss >> this->_doubleValue;
		if (!ss.fail())
		{
			this->_intValue = static_cast<int>(this->_doubleValue);
			this->_floatValue = static_cast<float>(this->_doubleValue);
		}
		else
			this->_type = _other;
	}
}

Cast::Cast(const Cast &src) : _value(src.getValue()), _type(src.getType())
{
}

Cast::~Cast()
{
}

Cast&	Cast::operator=(const Cast &src)
{
	if (this != &src)
	{
		this->_value.assign(src.getValue());
		this->_type = src.getType();
	}
	return (*this);
}

std::string	Cast::getValue(void) const
{
	return (this->_value);
}

t_type		Cast::getType(void) const
{
	return (this->_type);
}

int Cast::getIntValue(void) const
{
	return (this->_intValue);
}

float Cast::getFloatValue(void) const
{
	return (this->_floatValue);
}

double Cast::getDoubleValue(void) const
{
	return (this->_doubleValue);
}

int		Cast::getPrecision(void) const
{
	return (this->_precision);
}

void	Cast::setPrecision(void)
{
	if (this->getValue().find(".") != std::string::npos)
		this->_precision = this->getValue().length() - this->getValue().find(".");
}

t_type		Cast::getValueType(void) const
{
	t_type	result = _other;
	int		pointNb = 0;
	int		fNb = 0;

	for (int i = 0; i < static_cast<int>(this->getValue().length()); i++)
	{
		if (!std::isdigit(this->getValue().at(i)))
		{
			if (this->getValue().at(i) == '.')
			{
				pointNb++;
				if (pointNb > 1)
					return (_other);
			}
			else if (this->getValue().at(i) == 'f'
				&& i == static_cast<int>(this->getValue().length()) - 1)
				fNb++;
			else
				return (_other);
		}
	}
	std::cout << "points" << pointNb << " " << fNb << std::endl;
	if (pointNb == 0 && fNb == 0)
	{
		result = _int;
	}
	else if (pointNb == 1 && fNb == 0)
		result = _double;
	else if (pointNb == 1 && fNb == 1)
		result = _float;
	return (result);
}

char		Cast::toChar(void) const
{
	if (this->getType() == _other 
		|| this->getIntValue() < 0 || this->getIntValue() > 127)
		throw Cast::ImpossibleException();
	else if (this->getIntValue() < 32 || this->getIntValue() > 126)
		throw Cast::NotDisplayableException();
	return (this->getIntValue());
}

int			Cast::toInt(void) const
{
	if (this->getType() == _other && this->getValue().compare("+inf")
		&& this->getValue().compare("-inf"))
		throw Cast::ImpossibleException();
	else if (!this->getValue().compare("+inf"))
		return (IMAX);
	else if (!this->getValue().compare("-inf"))
		return (IMIN);
	return (this->getIntValue());
}

float		Cast::toFloat(void) const
{
	if (this->getType() == _other && this->getValue().compare("+inf")
		&& this->getValue().compare("-inf") && this->getValue().compare("nan"))
		throw Cast::ImpossibleException();
	else if (!this->getValue().compare("+inf"))
		return (FMAX);
	else if (!this->getValue().compare("-inf"))
		return (FMIN);
	else if (!this->getValue().compare("nan"))
		throw Cast::NanException();
	return (this->getIntValue());
}

double		Cast::toDouble(void) const
{
	if (this->getType() == _other && this->getValue().compare("+inf")
		&& this->getValue().compare("-inf") && this->getValue().compare("nan"))
		throw Cast::ImpossibleException();
	else if (!this->getValue().compare("+inf"))
		return (FMAX);
	else if (!this->getValue().compare("-inf"))
		return (FMIN);
	else if (!this->getValue().compare("nan"))
		throw Cast::NanException();
	return (this->getIntValue());
}

const char*	Cast::NotDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char*	Cast::ImpossibleException::what() const throw()
{
	return ("Impossible");
}

const char*	Cast::NanException::what() const throw()
{
	return ("nan");
}

std::ostream&	operator<<(std::ostream& os, Cast &src)
{
	os << "value: " << src.getValue() << " type: " << src.getType();
	os << std::endl;
	os << "int" << src.getIntValue() << " double " << src.getDoubleValue() << " float " << src.getFloatValue();
	os << std::endl;
	os << "char: '";
	try
	{
		os << src.toChar();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	os << "'" << std::endl;
	os << "int: ";
	try
	{
		os << src.toInt();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "float: ";
	try
	{
		os << src.toFloat() << "f";
	}
	catch(const Cast::NanException &e)
	{
		std::cerr << e.what() << "f";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	os << std::endl;
	std::cout << "double: ";
	try
	{
		os << src.toDouble();
	}
	catch(const Cast::NanException &e)
	{
		std::cerr << e.what();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	os << std::endl;
	return (os);
}