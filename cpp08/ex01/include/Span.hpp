/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:21:16 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/10 12:40:27 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
	unsigned int		_spanMaxSize;
	std::vector<int>	_spanVector;
public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	Span	&operator=(const Span &src);

	unsigned int		getMaxSize(void) const;
	unsigned int		getActualSize(void) const;
	int					getAt(int n) const;
	std::vector<int>	getVector(void) const;

	void	addNumber(int n);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
	void	addRange(std::vector<int>::iterator begin,
		std::vector<int>::iterator end);

	class OutOfRangeException : public std::exception
	{public: const char *what() const throw();};
	class SortException : public std::exception
	{public: const char *what() const throw();};
};

std::ostream&	operator<<(std::ostream& os, const Span& src);

#endif