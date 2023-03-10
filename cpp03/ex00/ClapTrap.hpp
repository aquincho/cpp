/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:18:24 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 12:21:37 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &copy);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	energyLeft(void) const;
};

#endif