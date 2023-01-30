/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:53 by aquincho          #+#    #+#             */
/*   Updated: 2023/01/30 11:45:25 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	
	const int		arraySize = 4;
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	Animal*	 		animals[arraySize];
	
	std::cout << std::endl;
	std::cout << "dog: " << j->getType() << std::endl;
	j->makeSound();
	std::cout << "cat: " << i->getType() << std::endl;
	i->makeSound();

	std::cout << std::endl;
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
	Cat felix;
	Cat titi(felix);
	std::cout << "Idea felix " << felix.getIdea(0) << "Idea titi " << titi.getIdea(0) << std::endl;
	titi.setIdea(0, "I am a canari");
	titi.setType("canari");
	std::cout << "Idea titi " << titi.getIdea(0) << std::endl;
	std::cout << "titi " << titi.getIdea(0) << " felix " << felix.getIdea(0) << std::endl;
	std::cout << "titi " << titi.getType() << " felix " << felix.getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << "delete de dog" << std::endl;
	delete j;
	std::cout << "delete de cat" << std::endl;
	delete i;
	std::cout << "delete de animals" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
	std::cout << std::endl;
	std::cout << "fin et sortie" << std::endl;
	return (0);
}
