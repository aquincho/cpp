/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:39:53 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 14:35:47 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &copy);

	void		HighFivesGuys(void);
};


#endif