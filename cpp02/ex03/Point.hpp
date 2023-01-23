/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:37:56 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 14:56:46 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point(Point const &copy);
	~Point();
	Point(const float x, const float y);

	Point	&operator=(Point const &copy);

	Fixed	getX(void);
	Fixed	getY(void);
	
	Fixed	getCoord(char c) const;
	void	printCoord(void);
};

bool	bsp(Point a, Point b, Point c, Point point);

#endif