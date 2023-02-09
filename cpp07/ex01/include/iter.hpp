/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:05:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/09 09:17:33 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T>
void	iter(T *array, size_t arraySize, void (*f)(T &))
{
	if (!array || f == NULL)
		return ;
	for (int i = 0; i < (int)arraySize; i++)
		f(array[i]);
}

#endif