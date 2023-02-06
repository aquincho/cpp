/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:21 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/06 11:33:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::srand((unsigned) time(NULL));
	Base	*test;

	for (int i = 0; i < 10; i++)
	{
		test = generate();
		identify(test);
		identify(*test);
		std::cout << std::endl;
		delete test;
	}
}