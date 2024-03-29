/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:16:15 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/16 11:00:28 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <cstdlib>
# include <cctype>
# include <map>

class BitcoinExchange
{
private:
	bool							_status;
	std::map<std::string, float>	_base;

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange& src);

	bool	getStatus(void) const;
	size_t	getSize() const;
	
	void		loadDatabase(const char* arg);
	void		fillLineMap(std::string line);
	bool		checkDateFormat(std::string date);
	void		resolveValue(std::string line);
	float		findValue(const std::string& date) const;
	void		printData(std::string* date) const;
	std::string	*checkInput(std::string line);
	std::string *splitIn2(std::string str, std::string sep);

	class InvalidDataException
	{private:
		std::string	_data;
	public:
		InvalidDataException(std::string data): _data(data) {};
		~InvalidDataException() {};
		const std::string what() const throw();};
	class InvalidDateException
	{private:
		std::string	_date;
	public:
		InvalidDateException(std::string date): _date(date) {};
		~InvalidDateException() {};
		const std::string what() const throw();};
	class NegativeNumber: public std::exception
	{public: virtual const char* what() const throw();};
	class TooLargeNumber: public std::exception
	{public: virtual const char* what() const throw();};
	class TooLowDateException: public std::exception
	{public: virtual const char* what() const throw();};
};

std::string *splitIn2(std::string str, std::string sep);

#endif