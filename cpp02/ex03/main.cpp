/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:26 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 16:07:29 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point	a(0, 0);
	Point	b(5, 0);
	Point	c(0.0f, 5.0f);
	Point	point(0, 0);
	Point	point2(100, 100);
	
	std::cout << "triangle 0,0 5,0 0,5 point 0,0" << std::endl;
	if( bsp(a, b, c, point)  )
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "triangle 0,0 5,0 0,5 point 100,100" << std::endl;
	if( bsp(a, b, c, point2)  )
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	Point	d(-1, 1);
	Point	e(3, 1);
	Point	f(2.0f, 5.0f);
	Point	point3(1, 2);

	std::cout << "triangle -1,1 3,1 2,5 point 1,2" << std::endl;
	if( bsp(d, e, f, point3)  )
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	Point	g(0, 0);
	Point	h(-5, 0);
	Point	i(0, -5);
	Point	point4(1, 1);

	std::cout << "triangle 0,0 -5,0 0,-5 point 1,1" << std::endl;
	if( bsp(g, h, i, point4)  )
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

return 0;
}