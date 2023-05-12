/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:20:39 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/12 11:54:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _status(true)
{
	try
	{
		this->loadDatabase("./data/data.csv");
	}
	catch(BitcoinExchange::InvalidDateException& d)
	{
		std::cerr << d.what() << "\n";
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

size_t	BitcoinExchange::getSize() const
{
	return (this->_base.size());
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
		this->fillLineMap(buffer);
		std::getline(dbFile, buffer);
	}
	dbFile.close();
}

void	BitcoinExchange::fillLineMap(std::string line)
{
	std::string	*split = NULL;

	split = splitIn2(line, ",");
	if (checkDateFormat(split[0]))
	{
		this->_base.insert(std::pair<std::string, float>(split[0],
			std::strtof(split[1].c_str(), NULL)));
	}
	else
	{
		this->_status = false;
		throw BitcoinExchange::InvalidDataException();
	}
}

bool	BitcoinExchange::checkDateFormat(std::string date)
{
	if (date.length() != 10)
		throw BitcoinExchange::InvalidDateException(date);
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(date.at(i)))
			throw BitcoinExchange::InvalidDateException(date);
	}
	if (!(std::isdigit(date.at(5)) && std::isdigit(date.at(6)) && (date.at(5) == '0'
		|| (date.at(5) == '1' && date.at(6) <= '2'))))
		throw BitcoinExchange::InvalidDateException(date);
	if (!(std::isdigit(date.at(8)) && std::isdigit(date.at(9)) && (date.at(8) < '3'
		|| (date.at(8) == '3' && date.at(9) <= '1'))))
		throw BitcoinExchange::InvalidDateException(date);
	if (date.at(4) != '-' || date.at(7) != '-')
		throw BitcoinExchange::InvalidDateException(date);
	return (true);
}

float	BitcoinExchange::findValue(const std::string& date) const
{
	std::cout << (--this->_base.upper_bound(date))->first << " - ";
	std::cout << (--this->_base.upper_bound(date))->second << std::endl;
	return ((--this->_base.upper_bound(date))->second);
}

void	BitcoinExchange::printData()
{
	std::map<std::string, float>::iterator	itb;
	std::map<std::string, float>::iterator	ite;
	
	itb = this->_base.begin();
	ite = this->_base.end();
	for(std::map<std::string, float>::iterator it = itb; it != ite; ++it)
		std::cout << it->first << " - " << it->second << std::endl;
}

std::string	*splitIn2(std::string str, std::string sep)
{
	std::string				*result = new std::string[2];
	std::string::size_type	pos = str.find(sep);

	if (pos == str.npos)
	{
		delete [] result;
		throw std::out_of_range("Wrong data: " + str);
	}
	result[0] = str.substr(0, pos);
	result[1] = str.substr(pos + sep.length(), str.npos);
	return (result);
}

const char*	BitcoinExchange::InvalidDataException::what() const throw()
{
	return ("Invalid data");
}

const std::string BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Database incomplete: Invalid date: " + this->_date);
}