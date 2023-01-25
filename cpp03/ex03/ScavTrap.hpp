/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:17:56 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 14:35:55 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	
public:
	ScavTrap (void);
	ScavTrap (const ScavTrap &copy);
	ScavTrap (std::string name);
	~ScavTrap ();

	ScavTrap &operator=(const ScavTrap &copy);

	void	guardGate(void);
};


#endif