/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:24 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/16 13:36:01 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name);

	void		announce(void);
	std::string	get_name(void);


private:
	std::string	_name;
};

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

#endif
