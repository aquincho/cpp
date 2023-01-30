/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:40:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 09:43:22 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "Brain.hpp"

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
	virtual void		setIdea(const int i, const std::string idea);
	virtual std::string	getIdea(const int i) const;
	virtual void		makeSound(void) const;
};

#endif
