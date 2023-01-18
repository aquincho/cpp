/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:24 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/18 09:01:14 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name);

	void		announce(void) const;
	std::string	getName(void) const;
	void		setName(std::string name);


private:
	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
