/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:51 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 10:43:57 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat();
	Cat(const Cat &src);
	~Cat();

	Cat	&operator=(const Cat &src);

	void	makeSound(void) const;
};




#endif