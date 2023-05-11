/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:16:15 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/11 12:49:48 by aquincho         ###   ########.fr       */
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
	
	void	loadDatabase(const char* arg);
	void	fillLineMap(std::string line);
	void	findValue(const std::string& date) const;
	bool	checkDateFormat(std::string date);
	void	printData();

	class InvalidDataException: public std::exception
	{public: virtual const char* what() const throw();};
	class InvalidDateException: public std::exception
	{public: virtual const char* what() const throw();};
};

std::string *splitIn2(std::string str, std::string sep);

#endif