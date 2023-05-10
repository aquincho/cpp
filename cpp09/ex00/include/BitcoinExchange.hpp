/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:16:15 by aquincho          #+#    #+#             */
/*   Updated: 2023/05/10 12:49:37 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <map>

class BitcoinExchange
{
private:
	bool							_status;
	std::map<std::string, float>	_base;

	void	getData(std::string buffer);

public:
	BitcoinExchange(void);
	BitcoinExchange(const char* arg);
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange& src);

	bool	getStatus(void) const;
	
	void	loadDatabase(const char* arg);
	void	findValue(const std::string& date) const;

	class InvalidDataException: public std::exception
	{public: virtual const char* what() const throw();};
};

std::string *splitIn2(std::string str, std::string sep);

#endif