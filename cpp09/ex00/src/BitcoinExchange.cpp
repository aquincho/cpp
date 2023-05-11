/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:20:39 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/11 13:08:13 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _status(true)
{
	try
	{
		this->loadDatabase("./data/data.csv");
	}
	catch(const std::exception& e)
	{
		this->_status = false;
		std::cout << "la fin" << std::endl;
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
	std::cout << "ouvert... " << buffer << std::endl;
	while (!dbFile.eof())
	{
		if (!this->_status)
			throw(BitcoinExchange::InvalidDataException());
		std::getline(dbFile, buffer);
		this->fillLineMap(buffer);
	}
	dbFile.close();
}

void	BitcoinExchange::fillLineMap(std::string line)
{
	std::string	*split = NULL;

	std::cout << "je splite" << std::endl;
	split = splitIn2(line, ",");
	if (checkDateFormat(split[0]))
	{
		std::pair<std::map<std::string, float>::iterator, bool> ret;
		std::cout << "insert?" << std::endl;
		ret = this->_base.insert(std::pair<std::string, float>(split[0],
			std::strtof(split[1].c_str(), NULL)));
		std::cout << ret.first->second << " - " << ret.second << std::endl;;
	}
	else
	{
		std::cout << "bouhouhou" << std::endl;
		this->_status = false;
		throw BitcoinExchange::InvalidDataException();
	}
}

bool	BitcoinExchange::checkDateFormat(std::string date)
{
	std::cout << "je checke la date ";
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(date.at(i)))
			throw BitcoinExchange::InvalidDateException();
	}
	std::cout << "le mois " << date.at(5) << " " << date.at(6) << " ";
	if (!(std::isdigit(date.at(5)) && std::isdigit(date.at(6)) && (date.at(5) == '0'
		|| (date.at(5) == '1' && date.at(6) <= '2'))))
		throw BitcoinExchange::InvalidDateException();
	std::cout << "le jour ";
	if (!(std::isdigit(date.at(8)) && std::isdigit(date.at(9)) && (date.at(8) < '3'
		|| (date.at(8) == '3' && date.at(9) <= '1'))))
		throw BitcoinExchange::InvalidDateException();
	std::cout << "les tirets ";
	if (date.at(4) != '-' || date.at(7) != '-')
		throw BitcoinExchange::InvalidDateException();
	return (true);
}

void	BitcoinExchange::printData()
{
	std::map<std::string, float>::iterator	itb;
	std::map<std::string, float>::iterator	ite;
	
	itb = this->_base.begin();
	ite = this->_base.end();
	std::cout << "base" << std::endl;
	for(std::map<std::string, float>::iterator it = itb; it != ite; ++it)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}
	//std::string::size_type pos = buffer.find(",");
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

const char*	BitcoinExchange::InvalidDataException::what() const throw()
{
	return ("Invalid data");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Invalid date");
}