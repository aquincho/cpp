/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/25 16:34:03 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
private:
	
public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &copy);

	void	makeSound(void) const;
};

#endif