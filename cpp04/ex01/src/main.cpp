/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:53 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/27 10:02:57 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const int		arraySize = 4;
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();
	const Animal* titi;
	Animal didier(*dog);
	Animal* animals[arraySize];
	
	std::cout << std::endl;
	std::cout << "dog: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	titi = cat;
	std::cout << "titi: " << titi->getType() << std::endl;
	titi->makeSound();
	std::cout<< "didier:" << didier.getType() << std::endl;
	didier.makeSound();
	didier.setIdea(0, "I am didier");
	std::cout << didier.getIdea(0) << std::endl;

	
	for (int i = 0; i < arraySize / 2; i++)
	{
		animals[i] = new Dog();
		animals[i]->setIdea(0, "I am a dog");
	}
	for (int i = arraySize / 2; i < arraySize; i++)
	{
		animals[i] = new Cat();
		animals[i]->setIdea(0, "I am a cat");
	}
	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();
	std::cout << std::endl;
	
	Animal* noe(animals[0]);
	std::cout << "noe " << noe->getType() << std::endl;
	noe->makeSound();
	noe->setType("Cat");
	std::cout << "noe " << noe->getIdea(0) << " an0 " << animals[0]->getIdea(0) << std::endl;
	noe->setIdea(0, "I am a wolf");
	std::cout << "noe " << noe->getIdea(0) << " an0 " << animals[0]->getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "delete de dog" << std::endl;
	delete dog;
	std::cout << "delete de cat" << std::endl;
	delete cat;
	std::cout << "delete de animals" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
	std::cout << "fin et sortie" << std::endl;
	return (0);
}
