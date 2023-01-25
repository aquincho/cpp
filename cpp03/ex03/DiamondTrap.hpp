/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:17:06 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 15:24:42 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	DiamondTrap (void);
	DiamondTrap (const DiamondTrap &copy);
	DiamondTrap (std::string name);
	~DiamondTrap(void);

	DiamondTrap &operator=(const DiamondTrap &copy);

	void	whoAmI(void);
	void	attack(const std::string& target);
};

#endif