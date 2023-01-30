/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:24:10 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 15:25:56 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
private:
	std::string		_name;
	AMateria*		_item[4];
	int				_nbItems;
public:
	Character(void);
	Character(std::string name);
	Character(const Character &src);
	~Character();

	Character	&operator=(const Character &src);

	std::string	const & getName() const;
	int			getNbItems(void) const;
	void		listItems(void) const;
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, ICharacter& target);	
};




#endif