/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:20:23 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/10 12:48:34 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
try
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(8);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addNumber(6);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
try
{
	Span sp2 = Span(5);
	sp2.addNumber(42);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
try
{
	Span sp3 = Span(10);
	std::vector<int> vect;
	sp3.addNumber(37);
	vect.push_back(12);
	vect.push_back(16);
	vect.push_back(-42);
	vect.push_back(68);
	vect.push_back(42);
	vect.push_back(0);
	sp3.addRange(vect.begin(), vect.end());
	std::cout << sp3;
	sp3.addRange(vect.begin(), vect.end() - 3);
	std::cout << sp3;
	sp3.addRange(vect.begin(), vect.end());
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}

return 0;
}