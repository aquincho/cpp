/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:59:59 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/13 09:42:25 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack();
	MutantStack(const MutantStack<T> &src);
	~MutantStack();

	MutantStack<T>	&operator=(const MutantStack<T> &src);

	typedef typename MutantStack<T>::container_type::iterator iterator;

	iterator	begin(void);
	iterator	end(void);
};

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T> &src)
{
	if (this = &src)
		return (*this);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif