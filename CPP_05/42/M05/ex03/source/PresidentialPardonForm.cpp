/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:15:57 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:15:57 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    :   AForm("PresidentialPardonForm", PRES_GRADE_TO_SIGN, PRES_GRADE_TO_EXEC),
        _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
    :   AForm(obj),
        _target(obj._target)
{}

PresidentialPardonForm
&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

std::string             PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void    PresidentialPardonForm::executeAction(void) const
{
    std::cout   << _target + " has been pardoned by Zaphod Beeblebrox."
                << std::endl;
}