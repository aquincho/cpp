/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:30:20 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/09 13:17:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
private:
	unsigned int	_size;
	T				*_array;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &src);
	~Array();

	Array<T>&	operator=(const Array<T> &src);

	T				getIndexValue(unsigned int n) const;
	unsigned int	getSize(void) const;
	void			setIndexValue(unsigned int n, T value);

	class InvalidSizeException : public std::exception
	{public: virtual const char* what() const throw();};
};

template<class T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array);

template<class T>
Array<T>::Array(): _size(0), _array(new T())
{
}

template<class T>
Array<T>::Array(unsigned int n): _size(n), _array(NULL)
{
	try
	{
		this->_array = new T[n];
	}
	catch(const std::exception& e)
	{
		this->_size = 0;
		this->_array = NULL;
		std::cerr << "Cannet create array. Bad allocation" << std::endl;
	}
}

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
	this->_array[n] = value;
}

template<class T>
const char*	Array<T>::InvalidSizeException::what() const throw()
{
	return ("invalide array size");
}

template<class T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.getSize(); i++)
		os << array.getIndexValue(i) << "\n";
	os << std::endl;
	return (os);
}

#endif