/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:07:33 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/04 18:41:00 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)  :   _nbContact(0), _index(0)
{}

PhoneBook::~PhoneBook(void)
{
}

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

void            PhoneBook::displayAllContact(void)
{
    std::cout   << std::setw(10) << "index" << "|"
                << std::setw(10) << "first name" << "|"
                << std::setw(10) << "last name" << "|"
                << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < _nbContact; i++)
    {
        std::cout   << std::setw(10) << i << "|" 
                    << std::setw(10) << truncString(_contactTab[i].getFirstName()) << "|"
                    << std::setw(10) << truncString(_contactTab[i].getLastName()) << "|"
                    << std::setw(10) << truncString(_contactTab[i].getNickName()) << std::endl;
    }
}

void            PhoneBook::displayContact(int index)
{
    if (index >= 0 && index < MAX_NB_CONTACT)
    {
        std::cout   << std::setw(10) << "index" << "|"
                    << std::setw(10) << "first name" << "|"
                    << std::setw(10) << "last name" << "|"
                    << std::setw(10) << "nickname" << "|"
                    << std::setw(10) << "phone numb" << "|"
                    << std::setw(10) << "darkest secret" << std::endl;
        std::cout   << std::setw(10) << index << "|" 
                    << std::setw(10) << _contactTab[index].getFirstName() << "|"
                    << std::setw(10) << _contactTab[index].getLastName() << "|"
                    << std::setw(10) << _contactTab[index].getNickName() << "|"
                    << std::setw(10) << _contactTab[index].getPhoneNb() << "|"
                    << std::setw(10) << _contactTab[index].getDarkestSecret()
                    << std::endl;
    }
}

std::string     PhoneBook::truncString(std::string str)
{
    std::size_t maxLength = 9;
    std::size_t nbCharToErase = str.size() - maxLength;

    if (str.size() > maxLength)
    {
        str.replace(maxLength, 1, 1, '.');
        str.erase(maxLength + 1, nbCharToErase);
    }
    
    return str;
}
void            PhoneBook::search(int index)
{
    displayAllContact();
    displayContact(index);
}