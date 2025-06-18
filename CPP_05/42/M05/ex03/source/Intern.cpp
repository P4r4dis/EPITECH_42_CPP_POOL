/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:31 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 19:33:28 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
Intern::Intern(void)
{}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

Intern      &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern(void)
{}

static AForm *shrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *robotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *presidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm       *Intern::makeForm(const std::string &nameForm, const std::string &target)
{
    // AForm   *form = nullptr;
    const int nbForm = 3;
    const char *sample[nbForm] = {"shrubbery creation",
                                "robotomy request",
                                "presidential pardon"};

    AForm *(*createForm[nbForm])(const std::string &target) = { &shrubbery, &robotomy, &presidential};

    for (int i  = 0; i < nbForm; ++i)
    {
        if (nameForm == sample[i])
        {
            AForm *form = createForm[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Error: Form name doesn't exist." << std::endl;
    return nullptr;
}