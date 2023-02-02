/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:51 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 09:00:52 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain*	_brain;

public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();

	Cat	&operator=(const Cat &src);

	std::string	getIdea(const int i) const;
	void		setIdea(const int i, const std::string idea);
	void		makeSound(void) const;
};




#endif