/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:29:22 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 11:26:31 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	
public:
	WrongCat(void);
	WrongCat(const WrongCat &src);
	~WrongCat();

	WrongCat& operator=(const WrongCat &src);

	void	makeSound(void) const;
};

#endif