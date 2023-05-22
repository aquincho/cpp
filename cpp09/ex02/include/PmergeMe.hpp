/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:04:24 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/22 09:14:38 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>
# include <ctime>

#define INSERTIONSIZE 4

class PmergeMe
{
private:
	std::vector<unsigned int>	_unsortedVector;
	std::deque<unsigned int>	_unsortedDeque;
	double						_deltaTimeVector;
	double						_deltaTimeDeque;

	PmergeMe();

	void	fillContainers(int argc, char **argv);
	template <typename T>
	void	sortContainer(T& container);
	template <typename T>
	void	printContainer(T& container) const;
	template <typename T>
	void	insertSort(T& container);
	template <typename T>
	void	mergeSort(T& container, T& left, T& right);
	
public:
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& src);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& src);

	std::vector<unsigned int>	getVector(void) const;
	std::deque<unsigned int>	getDeque(void) const;
	double						getDeltaTimeVector(void) const;
	double						getDeltaTimeDeque(void) const;
	
	void	sort(void);
	void	printResult(void);

	class NegativeNumberException: public std::exception
	{public: virtual const char* what() const throw();};
	class DuplicateNumberException: public std::exception
	{public: virtual const char* what() const throw();};
	class PmergeMeException: public std::exception
	{public: virtual const char* what() const throw();};
};

std::ostream&	operator<<(std::ostream& os, const PmergeMe& src);

#endif