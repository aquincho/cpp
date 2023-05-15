/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:07:27 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/15 15:47:43 by aquincho         ###   ########.fr       */
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

int		RPN::calculate(void)
{
	
	for(std::string::iterator it = this->_input.begin(); it != _input.end(); ++it)
	{
		
		
		std::cout << "*it: " << *it << std::endl;
		if (*it >= '0' && *it <= '9')
		{
			
			this->_operands.push(*it - '0');
			std::cout << "Add oper: " << *it << " " << this->_operands.top() << std::endl;
		}
		/*else if (*it == ' ')
			++it;*/
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			int tmp = 0;
			if (this->_operands.size() < 2)
				throw InvalidInputException();
			tmp = this->_operands.top();
			std::cout << "tmp1: " << tmp << std::endl;
			this->_operands.pop();
			switch (*it)
			{
			case '+':
				tmp += this->_operands.top();
				break;
			case '-':
				tmp -= this->_operands.top();
				break;
			case '*':
				tmp *= this->_operands.top();
				break;
			case '/':
			{
				if (this->_operands.top() != 0)
					tmp /= this->_operands.top();
				else
					throw DivisionByZeroException();
				break;
			}
			default:
				break;
			}
			this->_operands.push(tmp);
		}
	}
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
