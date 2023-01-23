/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:26 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/23 12:33:15 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
/*Fixed d(b);
std::cout << --d << std::endl;
std::cout << d << std::endl;
std::cout << d-- << std::endl;
std::cout << d << std::endl;
Fixed const c( Fixed( 5.10f ) / Fixed( 2 ) );
std::cout << c << std::endl;
std::cout << Fixed::min( c, d ) << std::endl;*/
return 0;
}