/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:05:58 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/17 15:29:38 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv): _deltaTimeVector(0), _deltaTimeDeque(0)
{
	try
	{
		this->fillContainers(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw PmergeMeException();
	}
}

PmergeMe::PmergeMe(const PmergeMe& src): _unsortedVector(src._unsortedVector),
_unsortedDeque(src._unsortedDeque), _deltaTimeVector(src._deltaTimeVector),
_deltaTimeDeque(src._deltaTimeDeque)
{}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		this->_unsortedVector = src._unsortedVector;
		this->_unsortedDeque = src._unsortedDeque;
	}
	return (*this);
}

std::vector<unsigned int>	PmergeMe::getVector(void) const
{
	return (this->_unsortedVector);
}

std::deque<unsigned int>		PmergeMe::getDeque(void) const
{
	return (this->_unsortedDeque);
}

double	PmergeMe::getDeltaTimeVector(void) const
{
	return (this->_deltaTimeVector);
}

double	PmergeMe::getDeltaTimeDeque(void) const
{
	return (this->getDeltaTimeDeque());
}

void	PmergeMe::sort(void)
{
	clock_t startTimeVector = clock();
	this->sortContainer(this->_unsortedVector);
	this->_deltaTimeVector = std::clock() - startTimeVector;
	clock_t startTimeDeque = std::clock();
	this->sortContainer(this->_unsortedDeque);
	this->_deltaTimeDeque = std::clock() - startTimeDeque;
}

void	PmergeMe::printResult(void)
{
	std::cout << "Before:\t";
	this->printContainer(this->_unsortedVector);
	this->sort();
	std::cout << "After:\t";
	this->printContainer(this->_unsortedVector);
	std::cout << "Time to process a range of \t" << this->_unsortedVector.size();
	std::cout << " elements with std::vector : ";
	std::cout << std::cout.setf(std::ios::fixed) << this->_deltaTimeVector / CLOCKS_PER_SEC;
	std::cout << " us" << std::endl;
	std::cout << "Time to process a range of \t" << this->_unsortedDeque.size();
	std::cout << " elements with std::vector : " << this->_deltaTimeDeque / CLOCKS_PER_SEC;
	std::cout << " us" << std::endl;
}

void	PmergeMe::fillContainers(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int	value = std::atoi(argv[i]);
		if (value < 0)
			throw NegativeNumberException();
		if (std::find(this->_unsortedVector.begin(), this->_unsortedVector.end(),
			value) != this->_unsortedVector.end())
			throw DuplicateNumberException();
		this->_unsortedVector.push_back(std::atoi(argv[i]));
		this->_unsortedDeque.push_back(std::atoi(argv[i]));
	}
}

template <typename T>
void	PmergeMe::sortContainer(T& container)
{
	const int	size = container.size();
	if (size < 2)
		return ;
	if (size < INSERTIONSIZE)
	{
		this->insertSort(container);
		return ;
	}
	typename T::iterator begin = container.begin();
	typename T::iterator middle = container.begin() + (size / 2);
	typename T::iterator end = container.end();
	T left(begin, middle);
	T right(middle, end);
	this->sortContainer(left);
	this->sortContainer(right);
	this->mergeSort(container, left, right);
}

template <typename T>
void	PmergeMe::printContainer(T& container) const
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::insertSort(T& container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		typename T::iterator j = it;
		while (j != container.begin() && *(j - 1) > *j)
		{
			std::swap(*j, *(j - 1));
			--j;
		}
	}
}

template <typename T>
void	PmergeMe::mergeSort(T& container, T& left, T& right)
{
	typename T::iterator i = left.begin();
	typename T::iterator j = right.begin();
	typename T::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}
	while (i != left.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

const char*	PmergeMe::NegativeNumberException::what() const throw()
{
	return ("Error: numbers must be positive");
}

const char*	PmergeMe::DuplicateNumberException::what() const throw()
{
	return ("Error: duplicate numbers");
}

const char*	PmergeMe::PmergeMeException::what() const throw()
{
	return ("Error: Cammot build sorted container");
}

std::ostream&	operator<<(std::ostream& os,const PmergeMe& src)
{
	for (unsigned int i = 0; i < src.getVector().size(); i++)
		std::cout << src.getVector().at(i) << " ";
	std::cout << std::endl;
	return (os);
}
