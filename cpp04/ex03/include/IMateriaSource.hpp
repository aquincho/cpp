/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:17:01 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 13:18:54 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
private:
	
public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif