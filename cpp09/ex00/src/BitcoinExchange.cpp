/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:20:39 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/15 12:11:49 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _status(false)
{
	try
	{
		this->loadDatabase("./data/data.csv");
	}
	catch(BitcoinExchange::InvalidDateException& date)
	{
		std::cerr << date.what() << "\n";
	}
	catch(BitcoinExchange::InvalidDataException& data)
	{
		std::cerr << data.what() << "\n";
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

	std::ifstream	dbFile;
	std::string		buffer;

	dbFile.open(arg, std::ifstream::in);
	std::getline(dbFile, buffer);
	std::getline(dbFile, buffer);
	while (!dbFile.eof())
	{
		this->fillLineMap(buffer);
		std::getline(dbFile, buffer);
	}
	dbFile.close();
}

void	BitcoinExchange::fillLineMap(std::string line)
{
	std::string*	split;

	this->_status = false;
	split = this->splitIn2(line, ",");
	if (!split)
	{
		std::cout << "test " << line << std::endl;
		throw BitcoinExchange::InvalidDataException(line);
	}
	else if (!this->checkDateFormat(split[0]))
	{
		std::string	date = std::string(split[0]);
		delete [] split;
		throw BitcoinExchange::InvalidDateException(date);
	}
	else
	{
		this->_status = true;
		this->_base.insert(std::pair<std::string, float>(split[0],
			std::strtof(split[1].c_str(), NULL)));
		delete [] split;
	}
}

bool	BitcoinExchange::checkDateFormat(std::string date)
{
	if (date.length() != 10)
		return (false);
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(date.at(i)))
			return (false);
	}
	if (!(std::isdigit(date.at(5)) && std::isdigit(date.at(6)) && (date.at(5) == '0'
		|| (date.at(5) == '1' && date.at(6) <= '2'))))
		return (false);
	if (!(std::isdigit(date.at(8)) && std::isdigit(date.at(9)) && (date.at(8) < '3'
		|| (date.at(8) == '3' && date.at(9) <= '1'))))
		return (false);
	if (date.at(4) != '-' || date.at(7) != '-')
		return (false);
	return (true);
}

void	BitcoinExchange::resolveValue(std::string line)
{
	try
	{
		std::string*	split;
		
		split = this->checkInput(line);
		this->printData(split);
		delete [] split;
	}
	catch(BitcoinExchange::InvalidDateException& date)
	{
		std::cerr << date.what() << "\n";
	}
	catch(BitcoinExchange::InvalidDataException& data)
	{
		std::cerr << data.what() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

float	BitcoinExchange::findValue(const std::string& date) const
{
	return ((--this->_base.upper_bound(date))->second);
}

void	BitcoinExchange::printData(std::string* date) const
{
	float	value = std::strtof(date[1].c_str(), NULL);

	if (value < 0)
		throw NegativeNumber();
	else if (value > 1000)
		throw TooLargeNumber();
	std::cout << date[0] << " => " << date[1] << " = ";
	std::cout << this->findValue(date[0]) * std::strtof(date[1].c_str(), NULL);
	std::cout << std::endl;
}

std::string*	BitcoinExchange::checkInput(std::string line)
{
	std::string* split;

	split = this->splitIn2(line, " | ");
	if (!split)
		throw InvalidDataException(std::string(line));
	else if (!this->checkDateFormat(split[0]))
	{
		std::string date = split[0];
		delete [] split;
		throw BitcoinExchange::InvalidDateException(date);
	}
	else
		return (split);
}

std::string*	BitcoinExchange::splitIn2(std::string str, std::string sep)
{
	std::string				*result = new std::string[2];
	std::string::size_type	pos = str.find(sep);

	if (pos == str.npos)
	{
		delete [] result;
		return (NULL);
	}
	result[0] = str.substr(0, pos);
	result[1] = str.substr(pos + sep.length(), str.npos);
	return (result);
}

const std::string	BitcoinExchange::InvalidDataException::what() const throw()
{
	return ("Error: bad input => " + this->_data);
}

const std::string	BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: bad date => " + this->_date);
}

const char*	BitcoinExchange::NegativeNumber::what() const throw()
{
	return ("Error: not a positive number.");
}

const char*	BitcoinExchange::TooLargeNumber::what() const throw()
{
	return ("Error: too large a number.");
}
