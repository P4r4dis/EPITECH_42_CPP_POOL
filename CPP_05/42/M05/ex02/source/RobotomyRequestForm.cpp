/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:54:42 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/17 21:41:19 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    :   AForm("RobotomyRequestForm", ROBOT_GRADE_TO_SIGN, ROBOT_GRADE_TO_EXEC),
        _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    :   AForm(obj),
        _target(obj._target)
{}

RobotomyRequestForm
&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

std::string             RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

void    RobotomyRequestForm::executeAction(void) const
{
    std::srand(std::time(0));
    if ((std::rand() % 2) == 0)
        std::cout   << _target << " has been robotomized successfully."
                    << std::endl;
    else
        std::cout   << _target << " robotomization failed."
                    << std::endl;
}