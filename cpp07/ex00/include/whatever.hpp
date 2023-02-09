/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:51:57 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/06 12:00:24 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

template <typename U>
U	min(const U& left, const U& right)
{
	return ((left <= right) ? left : right);
}

template <typename V>
V	max(const V& left, const V& right)
{
	return ((left >= right) ? left : right);
}