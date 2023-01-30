/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:43:44 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 11:03:01 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain(void);
	Brain(const Brain &src);
	~Brain();

	Brain	&operator=(const Brain &src);

	void		setIdea(const int i, const std::string idea);
	void		setFirstIdeas(void);
	std::string	getIdea(const int i) const;
};

std::string	ft_iToStr(int i);

#endif