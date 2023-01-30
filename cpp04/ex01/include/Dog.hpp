/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 12:36:18 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain*	_brain;

public:
	Dog(void);
	Dog(const Dog &src);
	~Dog();

	Dog &operator=(const Dog &src);

	std::string	getIdea(const int i) const;
	void		setIdea(const int i, const std::string idea);
	void		makeSound(void) const;
};

#endif