/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:31:21 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/09 11:57:00 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T>
Array<T>::Array(void): _size(0), _array(NULL)
{
	//this->_array = new T[1];
}

template<class T>
Array<T>::Array(unsigned int n): _size(n), _array(NULL)
{
	try
	{
		if (this->_size < 0)
			throw Array<T>::InvalidSizeException();
		this->_array = new T[this->_size];
		if (!this->_array)
			throw std::exception();
	}
	catch(Array<T>::InvalidSizeException &e)
	{
		std::cerr << "Cannot create array. " << e.what() << '\n';
	}
	catch(const std::exception &e)
	{
		std::cerr <<e.what() << '\n';
	}
}
/*
template<class T>
Array<T>::Array(const Array<T> &src): _size(src.getSize())
{
	this->_array = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = src->_array[i];
}

template<class T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template<class T>
Array<T>&	Array<T>::operator=(const Array<T> &src)
{
	if (this = &src)
		return (*this);
	this->_size = src._size;
	if (this->_array)
		delete [] this->_array;
	this->_array = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
	return (*this);
}

template<class T>
T				Array<T>::getIndexValue(unsigned int n) const
{
	return (this->_array[n]);
}

template<class T>
unsigned int	Array<T>::getSize(void) const
{
	return (this->_size);
}

template<class T>
void			Array<T>::setIndexValue(unsigned int n, T value)
{
	this->array[n] = value;
}

template<class T>
void			Array<T>::printArray(void) const
{
	for (int i = 0; i < this->_size; i++)
		std::cout << i << ": " << this->_array[i] << "\n";
}

template<class T>
const char*	Array<T>::InvalidSizeException::what() const throw()
{
	return ("invalide array size");
}

template<class T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array)
{
	os << array.printArray();
	return (os);
}*/
