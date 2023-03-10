/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:40:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 12:00:12 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal &src);
	Animal(std::string type);
	virtual ~Animal();

	Animal	&operator=(const Animal &src);

	std::string			getType(void) const;
	void				setType(std::string type);
	virtual void		makeSound(void) const;
};

#endif
