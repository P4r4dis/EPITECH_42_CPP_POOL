/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:55:34 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 16:49:40 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include <cstddef>

const char      *Form::GradeTooHighException::what(void) const throw()
{
    return ("Error: Grade is too high.");
}

const char      *Form::GradeTooLowException::what(void) const throw()
{
    return ("Error: Grade is too low.");
}

Form::Form(const std::string &name, const size_t gradeToSign,
            const size_t gradeToExecute) :  _name(name),
                                            _isSigned(false),
                                            _gradeToSign(gradeToSign),
                                            _gradeToExecute(gradeToExecute)
                                            
{
    if (_gradeToSign < HIGHEST || _gradeToExecute < HIGHEST)
        throw Form::GradeTooHighException();
    else if (_gradeToSign > LOWEST || _gradeToExecute > LOWEST)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &cpy) :   _name(cpy._name),
                                _isSigned(cpy._isSigned),
                                _gradeToSign(cpy._gradeToSign),
                                _gradeToExecute(cpy._gradeToExecute)
{
}

Form                    &Form::operator=(const Form &form)
{
    if (this != &form)
    {
        _name = form._name;
        _isSigned = form._isSigned;
        _gradeToSign = form._gradeToSign;
        _gradeToExecute = form._gradeToExecute;
    }
    return *this;
}

Form::~Form(void)
{}

const std::string       Form::getName(void) const
{
    return _name;
}

bool                    Form::getIsSigned(void) const
{
    return _isSigned;
}

size_t                  Form::getGradeToSign(void) const
{
    return _gradeToSign;
}

size_t                  Form::getGradeToExecute(void) const
{
    return _gradeToExecute;
}