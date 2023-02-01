/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:10:44 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/01 09:45:36 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"


class AMateria;

class ICharacter
{
private:
	
public:
	virtual ~ICharacter() {};
	virtual std::string	const & getName() const = 0;
	virtual void		equip(AMateria* m) = 0;
	virtual void		unequip(int idx) = 0;
	virtual void		use(int idx, ICharacter& target) = 0;
	virtual void		listItems(void) const = 0;
};

#endif