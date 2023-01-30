/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:41:11 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 11:11:59 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &src);

	std::string			getType(void) const;
	virtual void		makeSound(void) const;
};

#endif