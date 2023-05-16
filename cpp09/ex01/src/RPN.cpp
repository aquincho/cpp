/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:07:27 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/16 09:43:11 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char* arg): _input(std::string(arg))
{
	if (!this->checkInput(_input))
		throw InvalidInputException();
}

RPN::RPN(const RPN& src): _operands(src._operands)
{
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& src)
{
	if (this != &src)
		this->_operands = src._operands;
	return (*this);
}

std::string	RPN::getInput() const
{
	return (this->_input);
}

bool	RPN::checkInput(std::string input) const
{
	if (input.find_first_not_of("0123456789 +-*/") != std::string::npos
		|| input.find_first_of("0123456789") == std::string::npos
		|| input.find_first_of("+-*/") == std::string::npos)
		return (false);
	return (true);
}

double	RPN::calculate(void)
{
	
	for(std::string::iterator it = this->_input.begin(); it != _input.end(); ++it)
	{
		if (*it >= '0' && *it <= '9')
			this->_operands.push(static_cast<double>(*it - '0'));
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			double tmp = 0;
			if (this->_operands.size() < 2)
				throw InvalidInputException();
			tmp = this->_operands.top();
			this->_operands.pop();
			switch (*it)
			{
			case '+':
				tmp = this->_operands.top() + tmp;
				break;
			case '-':
				tmp = this->_operands.top() - tmp;
				break;
			case '*':
				tmp = this->_operands.top() * tmp;
				break;
			case '/':
			{
				if (this->_operands.top() != 0)
					tmp = this->_operands.top() / tmp;
				else
					throw DivisionByZeroException();
				break;
			}
			default:
				break;
			}
			this->_operands.pop();
			this->_operands.push(tmp);
		}
	}
	if(this->_operands.size() != 1)
		throw InvalidInputException();
	return (this->_operands.top());
}

const char*	RPN::InvalidInputException::what() const throw()
{
	return ("Error");
}

const char*	RPN::DivisionByZeroException::what() const throw()
{
	return ("Error: division by zero");
}

std::ostream&	operator<<(std::ostream &os, RPN& src)
{
	os << "Input: " << src.getInput() << std::endl;
	os << src.calculate() << std::endl;
	return (os);
}
