/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:07:33 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/01 16:57:40 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)  :   _nbContact(0)
{
    for (int  i = 0; i <= MAX_NB_CONTACT; i++)
        _contactTab[i] = nullptr;
}

PhoneBook::~PhoneBook(void)
{
}

int         PhoneBook::getNbContact(void) const
{
    return _nbContact;
}

Contact     *PhoneBook::getPtrContactTab(void) const
{
    return *_contactTab;
}

Contact     *PhoneBook::getContactTab(int index) const
{
    return _contactTab[index];
}

void        PhoneBook::setContact(Contact *contact)
{
    int index = 0;
    if (_contactTab[index] == nullptr)
        _contactTab[index] = contact;
    while (_contactTab[_nbContact] != nullptr)
        _nbContact++;
    index++;
}