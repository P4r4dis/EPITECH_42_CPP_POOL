/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:15:41 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:15:41 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/AForm.hpp"

const char      *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Error: Grade is too high.");
}

const char      *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Error: Grade is too low.");
}

const char      *AForm::FormNotSigned::what(void) const throw()
{
    return ("Error: is not signed.");
}

AForm::AForm(const std::string &name, const size_t gradeToSign,
            const size_t gradeToExecute) :  _name(name),
                                            _isSigned(false),
                                            _gradeToSign(gradeToSign),
                                            _gradeToExecute(gradeToExecute)
                                            
{
    if (_gradeToSign < HIGHEST || _gradeToExecute < HIGHEST)
        throw AForm::GradeTooHighException();
    else if (_gradeToSign > LOWEST || _gradeToExecute > LOWEST)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cpy) :   _name(cpy._name),
                                _isSigned(cpy._isSigned),
                                _gradeToSign(cpy._gradeToSign),
                                _gradeToExecute(cpy._gradeToExecute)
{
}

AForm                    &AForm::operator=(const AForm &form)
{
    if (this != &form)
        _isSigned = form._isSigned;
    return *this;
}

AForm::~AForm(void)
{}

const std::string       AForm::getName(void) const
{
    return _name;
}

bool                    AForm::getIsSigned(void) const
{
    return _isSigned;
}

size_t                  AForm::getGradeToSign(void) const
{
    return _gradeToSign;
}

size_t                  AForm::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

void                    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    else
        _isSigned = true;
}

std::ostream            &operator<<(std::ostream &os, const AForm &form)
{
    os  << "AForm name: " << form.getName() << std::endl
        << "AForm grade to sign: " << form.getGradeToSign() << std::endl
        << "AForm grade to execute: " << form.getGradeToExecute() << std::endl
        << std::boolalpha << "AForm is signed: " << form.getIsSigned();
    return os;
}

void                    AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSigned();
    else if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}