/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:04 by aquincho          #+#    #+#             */
/*   Updated: 2023/02/02 14:34:36 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 1, 150)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src), _target(src.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->AForm::operator=(src);
	this->_target.assign(src.getTarget());
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::doAction(void) const
{
	int	success;

	std::srand(std::time(NULL));
	success = 1 + std::rand() % 2;
	std::cout << success << std::endl;
	if (success == 1)
		std::cout << "SUCCESS!!! " << this->_target << " has been robotomized successfully!";
	else
		std::cout << "FAILURE!!! " << this->_target << " couldn't be robotomized!";
	std::cout << std::endl;
}