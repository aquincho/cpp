/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:06:56 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 16:03:53 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point a, Point b, Point c, Point point)
{
	Fixed	subArea1;
	Fixed	subArea2;
	Fixed	subArea3;
	Fixed	area;

	area = (((b.getX() - a.getX()) * (c.getY() - a.getY())) - 
		((c.getX() - a.getX()) * (b.getY() - a.getY()))) / 2;
	if (area < 0)
		area = area * -1;
	subArea1 = (((b.getX() - point.getX()) * (c.getY() - point.getY())) - 
		((c.getX() - point.getX()) * (b.getY() - point.getY()))) / 2;
	if (subArea1 < 0)
		subArea1 = subArea1 * -1;
	subArea2 = (((point.getX() - a.getX()) * (c.getY() - a.getY())) - 
		((c.getX() - a.getX()) * (point.getY() - a.getY()))) / 2;
	if (subArea2 < 0)
		subArea2 = subArea2 * -1;
	subArea3=  (((b.getX() - a.getX()) * (point.getY() - a.getY())) - 
		((point.getX() - a.getX()) * (b.getY() - a.getY()))) / 2;
	if (subArea3 < 0)
		subArea3 = subArea3 * -1;
	//std::cout << area << " " << subArea1 << " " << subArea2 << " " << subArea3 << " " << std::endl;
	if (area == (subArea1 + subArea2 + subArea3))
		return (true);
	else
		return (false);
}