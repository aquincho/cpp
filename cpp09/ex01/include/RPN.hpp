/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:33:09 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/15 15:33:15 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>

class RPN
{
private:
	std::string		_input;
	std::stack<int>	_operands;

	RPN();
	
public:
	RPN(char* arg);
	RPN(const RPN& src);
	~RPN();

	RPN&	operator=(const RPN& src);

	std::string	getInput() const;
	bool	checkInput(const std::string input) const;
	int		calculate(void);

	class InvalidInputException: public std::exception
	{public: virtual const char* what() const throw();};
	class DivisionByZeroException: public std::exception
	{public: virtual const char* what() const throw();};
};

std::ostream&	operator<<(std::ostream& os, RPN& src);

#endif