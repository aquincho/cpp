/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:40 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 12:59:03 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice(void);
	Ice(const Ice &src);
	~Ice();

	Ice &operator=(const Ice &src);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif