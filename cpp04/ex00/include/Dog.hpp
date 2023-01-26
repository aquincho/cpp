/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:19 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 10:45:22 by aquincho         ###   ########.fr       */
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
	Dog(const Dog &src);
	~Dog();

	Dog &operator=(const Dog &src);

	void	makeSound(void) const;
};

#endif