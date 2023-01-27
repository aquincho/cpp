/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:53 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 12:22:02 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	const Animal* k;
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