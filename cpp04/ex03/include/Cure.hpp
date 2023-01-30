/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:56:34 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 13:16:27 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure(void);
	Cure(const Cure &src);
	~Cure();

	Cure	&operator=(const Cure &src);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif