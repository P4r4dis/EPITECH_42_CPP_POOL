/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:07:33 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/03 18:42:44 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)  :   _nbContact(0), _index(0)
{}

PhoneBook::~PhoneBook(void)
{}

int         PhoneBook::getNbContact(void) const
{
    return _nbContact;
}


const Contact   *PhoneBook::getContactTab(void) const
{
    return _contactTab;
}

int             PhoneBook::getIndex(void) const
{
    return _index;
}
void            PhoneBook::addContact(Contact contact)
{
    if (_index < MAX_NB_CONTACT)
    {
        _contactTab[_index] = contact;
        _index++;
        _nbContact >= MAX_NB_CONTACT ? _nbContact = MAX_NB_CONTACT : _nbContact++;
    }
    else
    {
        if (_index >= MAX_NB_CONTACT)
            _index = 0;
        _contactTab[_index] = contact;
        _index++;
    }
}