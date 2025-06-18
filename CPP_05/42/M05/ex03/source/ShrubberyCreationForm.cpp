/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:16:11 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:16:11 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    :   AForm("ShrubberyCreationForm", GRADE_TO_SIGN, GRADE_TO_EXEC),
        _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    :   AForm(obj),
        _target(obj._target)
{}

ShrubberyCreationForm
&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

std::string             ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

void    ShrubberyCreationForm::executeAction(void) const
{
    std::fstream    file(_target + "_shrubbery", std::fstream::out);
    
    if (file.is_open())
    {
        file    << "       _-_" << std::endl;
        file    << "    /~~   ~~\\" << std::endl;
        file    << " /~~         ~~\\" << std::endl;
        file    << "{               }" << std::endl;
        file    << " \\  _-     -_  /" << std::endl;
        file    << "   ~  \\ //  ~" << std::endl;
        file    << "_- -   | | _- _" << std::endl;
        file    << "  _ -  | |   -_" << std::endl;
        file    << "      /   \\" << std::endl;
        file    << "     /     \\" << std::endl;
    }
    file.close();
}