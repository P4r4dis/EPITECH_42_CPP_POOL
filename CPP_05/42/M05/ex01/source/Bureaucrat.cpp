/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:26:02 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 18:52:01 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#include <exception>
#include <iostream>

const char      *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Error: Grade is too high.");
}

const char      *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Error: Grade is too low.");
}

Bureaucrat::Bureaucrat(const std::string &name, size_t grade) : _name(name),
                                                                _grade(grade)
{
    if (_grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > LOWEST)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{}

const std::string   Bureaucrat::getName(void) const
{
    return _name;
}

size_t              Bureaucrat::getGrade(void) const
{
    return _grade;
}

void                Bureaucrat::increment(void)
{
    if ((_grade - 1) < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    --_grade;
}

void                Bureaucrat::decrement(void)
{
    if ((_grade + 1) > LOWEST)
        throw Bureaucrat::GradeTooLowException();
    ++_grade;
}

std::ostream        &operator<<(std::ostream &os, const Bureaucrat &bureau)
{
    os  << bureau.getName() + ", bureaucrat grade " << bureau.getGrade()
        << ".";
    return os;
}

void                    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        if (form.getIsSigned())
            std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout   << _name << " couldn't sign " << form.getName()
                    << " because " << e.what() << std::endl;
    }
}