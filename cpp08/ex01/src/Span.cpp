/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:25:49 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/10 12:46:10 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _spanMaxSize(0)
{
}

Span::Span(unsigned int n): _spanMaxSize(n)
{
}

Span::Span(const Span &src):
_spanMaxSize(src._spanMaxSize)
{
	this->_spanVector.assign(src._spanVector.begin(), src._spanVector.end());
}

Span::~Span()
{
}

Span&	Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_spanVector = src._spanVector;
	this->_spanVector.assign(src._spanVector.begin(), src._spanVector.end());
	return (*this);
}

unsigned int		Span::getMaxSize(void) const
{
	return (this->_spanMaxSize);
}

unsigned int		Span::getActualSize(void) const
{
	return (this->_spanVector.size());
}

int					Span::getAt(int n) const
{
	return (this->_spanVector.at(n));
}

std::vector<int>	Span::getVector(void) const
{
	return (this->_spanVector);
}

void	Span::addNumber(int	n)
{
	if (this->_spanVector.size() < this->_spanMaxSize)
	{
		this->_spanVector.push_back(n);
		std::sort(this->_spanVector.begin(), this->_spanVector.end());
	}
	else
		throw Span::OutOfRangeException();
}

int		Span::shortestSpan(void) const
{
	int	result = this->longestSpan();

	if (this->_spanVector.size() <= 1)
		throw Span::SortException();
	for (std::vector<int>::const_iterator it = this->_spanVector.begin();
		it != (this->_spanVector.end() - 1); it++)
	{
		if (*(it + 1) - *it < result)
			result = *(it + 1) - *it;
	}
	return (result);
}

int		Span::longestSpan(void) const
{
	if (this->_spanVector.size() <= 1)
		throw Span::SortException();
	else
		return (*std::max_element(this->_spanVector.begin(), this->_spanVector.end())
			- *std::min_element(this->_spanVector.begin(), this->_spanVector.end()));
}

void	Span::addRange(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	long unsigned int	size = std::distance(begin, end);
	
	if (size <= this->_spanMaxSize - this->_spanVector.size())
	{
		for (std::vector<int>::const_iterator it = begin; it != end; ++it)
			this->addNumber(*it);
	}
	else
		throw Span::OutOfRangeException();

}

const char*	Span::OutOfRangeException::what() const throw()
{
	return "Span does not have enough space left for this";
}

const char*	Span::SortException::what() const throw()
{
	return "Span is too small to be sorted";
}

std::ostream&	operator<<(std::ostream& os, const Span& src)
{
	os << "Span size: " << src.getActualSize() << " / " << src.getMaxSize() << "\n";
	for (unsigned int i = 0; i < src.getActualSize(); i++)
		os << src.getAt(i) << " ";
	os << "\n";
	if (src.getActualSize() > 1)
		os << "shortest span: " << src.shortestSpan() << " longest span: " << src.longestSpan();
	os << std::endl;
	return (os);
}
