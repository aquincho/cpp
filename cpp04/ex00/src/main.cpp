/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:53 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/26 11:20:44 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "meta" <<std::endl;
	const Animal* meta = new Animal();
	std::cout << "j: dog" <<std::endl;
	const Animal* j = new Dog();
	std::cout << "i: wrong cat" <<std::endl;
	const WrongAnimal* i = new WrongCat();
	std::cout << "k" <<std::endl;
	const Animal* k;
	std::cout << "l: cat" <<std::endl;
	const Animal* l = new Cat();
	const Animal* copycat(l);
	
	std::cout << "i j" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "k" << std::endl;
	k = j;
	std::cout << k->getType() << std::endl;
	k->makeSound();
	std::cout << "l" << std::endl;
	std::cout << l->getType() << std::endl;
	l->makeSound();
	std::cout << "copycat" << std::endl;
	std::cout << copycat->getType() << std::endl;
	copycat->makeSound();
	delete i;
	delete j;
	delete l;
	delete meta;
	
	return (0);
}