/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:09:32 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:51 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrReplace.hpp"

StrReplace::StrReplace() : _pos(0), _status(0)
{
}

StrReplace::~StrReplace()
{
}

int	StrReplace::getStatus(void) const
{
	return (this->_status);
}

void	StrReplace::setStatus(int status)
{
	this->_status = status;
}

int	StrReplace::open(char *file)
{
	this->_inFile.open(file, std::ifstream::in);
	this->_outFile.open((std::string(file).append(".replace")).c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!this->_inFile.good() || !this->_outFile.good())
	{
		std::cout << "File name not recognized!" << std::endl;
		this->setStatus(1);
	}
	else
		this->setStatus(0);
	return (this->getStatus());
}

void	StrReplace::close()
{
	this->_inFile.close();
	this->_outFile.close();
}

void	StrReplace::replace(char *s1, char *s2)
{
	while (!this->_inFile.eof())
	{

		std::getline(this->_inFile, this->_buffer);
		this->_pos = this->_buffer.find(s1);
		while (this->_pos >= 0)
		{
			this->_buffer.erase(this->_pos, std::string(s1).size());
			this->_buffer.insert(this->_pos, std::string(s2));
			this->_pos = this->_buffer.find(s1, this->_pos + 1);
		}
		this->_outFile.write(this->_buffer.c_str(), this->_buffer.size());
		if (!this->_inFile.eof())
			this->_outFile.put('\n');
	}
}
