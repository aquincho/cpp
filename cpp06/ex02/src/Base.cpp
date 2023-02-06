/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:55 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/06 11:33:47 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base*	generate(void)
{
	int		random;

	random = rand() % 3;
	switch (random)
	{
	case 0:
		std::cout << "Creation type A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Creation type B" << std::endl;
		return (new B);
	case 2:
		std::cout << "Creation type C" << std::endl;
		return (new C);
	default:
		std::cout << "Error: random generator" << std::endl;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer identifiend as type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer identifiend as type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer identifiend as type C" << std::endl;
	else
		std::cout << "error: cannot find pointer type" << std::endl;
}

bool	testA(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool	testB(Base &p)
{
	try
	{
		dynamic_cast<B&>(p);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool	testC(Base &p)
{
	try
	{
		dynamic_cast<C&>(p);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

void	identify(Base& p)
{
	if (testA(p))
		std::cout << "reference identified as type A" << std::endl;
	else if (testB(p))
		std::cout << "reference identified as type B" << std::endl;
	else if (testC(p))
		std::cout << "reference identified as type C" << std::endl;
	else
		std::cout << "error: cannot find reference type" << std::endl;
}