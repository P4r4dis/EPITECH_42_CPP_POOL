/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:00:31 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/02 21:28:02 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact(void)
{
}

void            Contact::setFirstName(std::string firstName) 
{
    _firstName = firstName;
}

void            Contact::setLastName(std::string lastName) 
{
    _lastName = lastName;
}

void            Contact::setNickName(std::string nickName)
{
    _nickName = nickName;
}

void            Contact::setPhoneNb(std::string phoneNb)
{
    _phoneNb = phoneNb;
}

void            Contact::setDarkestSecret(std::string darkest_secret)
{
    _darkest_secret = darkest_secret;
}

void            Contact::setInfoContact(std::string firstName, std::string lastName,
                                        std::string nickName, std::string phoneNb,
                                        std::string darkest_secret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickName = nickName;
    _phoneNb = phoneNb;
    _darkest_secret = darkest_secret;
}

std::string     Contact::getFirstName(void) const
{
    return _firstName;
}

std::string     Contact::getLastName(void) const
{
    return _lastName;
}

std::string     Contact::getNickName(void) const
{
    return _nickName;
}

std::string     Contact::getPhoneNb(void) const
{
    return _phoneNb;
}

std::string     Contact::getDarkestSecret(void) const
{
    return _darkest_secret;
}