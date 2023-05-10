/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:20:39 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/10 12:56:40 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _status(true)
{
}

BitcoinExchange::BitcoinExchange(const char* arg): _status(true)
{
	try
	{
		this->loadDatabase(arg);
	}
	catch(const std::exception& e)
	{
		this->_status = false;
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src):
 _status(true), _base(src._base)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->_status = src._status;
		this->_base = src._base;	
	}
	return (*this);
}

bool	BitcoinExchange::getStatus(void) const
{
	return (this->_status);
}

void	BitcoinExchange::getData(std::string buffer)
{
	std::string::size_type pos = buffer.find(",");
	
}

void	BitcoinExchange::loadDatabase(const char* arg)
{

	std::ifstream dbFile;
	std::string buffer;

	dbFile.open(arg, std::ifstream::in);
	std::getline(dbFile, buffer);
	std::getline(dbFile, buffer);
	while (!dbFile.eof())
	{
		if (!this->_status)
			throw(BitcoinExchange::InvalidDataException());
		std::getline(dbFile, buffer);
	}
}

std::string	*splitIn2(std::string str, std::string sep)
{
	std::string				*result = new std::string[2];
	std::string::size_type	pos = str.find(sep);

	if (pos == str.npos)
	{
		delete [] result;
		throw std::out_of_range(result[0]);
	}
	result[0] = str.substr(0, pos);
	result[1] = str.substr(pos + sep.length(), str.npos);
	return (result);
}
