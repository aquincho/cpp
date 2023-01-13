/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:51 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/11 14:38:45 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account()
{
}

Account::~Account()
{
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "todo infos" << std::endl;
}

void	Account::displayStatus(void) const
{
	std::cout << "todo status" << std::endl;
}