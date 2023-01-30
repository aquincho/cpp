/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:25:32 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 15:24:29 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int			_nbLearned;
	AMateria**	_materiaLearned;	
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &src);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

#endif