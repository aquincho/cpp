/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:29:08 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/10 09:53:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class ItemNotFoundException : public std::exception
{
public:
	const char* what() const throw()
	{return "Value not found";} 
};



template<typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
		throw ItemNotFoundException();
	return (result);
}

#endif