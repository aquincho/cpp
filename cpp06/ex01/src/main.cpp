/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:44:54 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/06 10:30:49 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data		data1;
	Data		*data2;
	Data		newData1;
	Data		*newData2;
	uintptr_t	d1;
	uintptr_t	d2;

	data1.type = "data";
	data1.value = 42;
	
	data2 = new Data;
	data2->type = "data2";
	data2->value = 4242;

	std::cout << "Donnees de data1: " << "adress: " << &data1 << "\n";
	std::cout << "type: " << data1.type << "\n";
	std::cout << "value: " << data1.value << std::endl;
	std::cout << "Donnees de data2: " << "adress: " << data2 << "\n";
	std::cout << "type: " << data2->type << "\n";
	std::cout << "value: " << data2->value << std::endl;

	std::cout << "serialize:" << std::endl;
	d1 = serialize(&data1);
	d2 = serialize(data2);
	std::cout << "serialized d1: " << d1 << " serialized d2: " << d2 << std::endl;

	std::cout << "deserialize:" << std::endl;
	newData1 = *deserialize(d1);
	newData2 = deserialize(d2);

	std::cout << "Donnees de newData1: " << "adress: " << &newData1 << "\n";
	std::cout << "type: " << newData1.type << "\n";
	std::cout << "value: " << newData1.value << std::endl;
	std::cout << "Donnees de newData2: " << "adress: " << newData2 << "\n";
	std::cout << "type: " << newData2->type << "\n";
	std::cout << "value: " << newData2->value << std::endl;

	delete data2;
}