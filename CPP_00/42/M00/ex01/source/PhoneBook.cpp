/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:07:33 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/16 19:13:23 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)  :   _nbContact(0), _index(0), _input(""),
                                _exitCount(0)
{}

PhoneBook::~PhoneBook(void)
{
}

int             PhoneBook::getNbContact(void) const
{
    return _nbContact;
}

void            PhoneBook::setNbContact(int nbContact)
{
    if (nbContact >= 0 && nbContact < MAX_NB_CONTACT)
        _nbContact = nbContact;
}

const Contact   *PhoneBook::getContactTab(void) const
{
    return _contactTab;
}

void            PhoneBook::setContactTab(Contact newContactTab[MAX_NB_CONTACT]) 
{
    for (int i = 0; i < MAX_NB_CONTACT; ++i)
        _contactTab[i] = newContactTab[i];
}

int             PhoneBook::getIndex(void) const
{
    return _index;
}

void            PhoneBook::setIndex(int index)
{
    if (index >= 0 && index < MAX_NB_CONTACT)
        _index = index;
}

void            PhoneBook::addContact(Contact contact)
{
    _exitCount = 0;
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
    if (index >= 0 && index <= _nbContact)
    {
        std::cout   << "index: " << index << std::endl;
        std::cout   << "first name: " << _contactTab[index].getFirstName()
                    << std::endl;
        std::cout   << "last name: " << _contactTab[index].getLastName()
                    << std::endl;
        std::cout   << "nickname: " << _contactTab[index].getNickName()
                    << std::endl;
        std::cout   << "phone number: " << _contactTab[index].getPhoneNb()
                    << std::endl;
        std::cout   << "darkest secret: " << _contactTab[index].getDarkestSecret()
                    << std::endl;
    }
    else
        std::cout << "There is no contact enregistered to this index." << std::endl;
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

int             PhoneBook::validIndex(std::string input)
{
    int index = 0;
    bool validInput = false;

    while (!validInput)
    {
        std::cout << "Enter the contact index you wish to display:" << std::endl;
        std::getline(std::cin, input);
        validInput = true;
        for (size_t i = 0; i < input.length(); ++i)
            if ((input[i] >= '!' && input[i] <= '/') || (input[i] >= ':' && input[i] <= '~'))
                validInput = false;
        if (validInput)
        {
            std::stringstream convert(input);
            convert >> index;
            if (index < 0 || index > _nbContact)
            {
                std::cout << "Index out of range. Please try again." << std::endl;
                validInput = false;
            }
        }
        else
            std::cout << "Invalid input. Please enter a number." << std::endl;
    }

    return index;
}
void            PhoneBook::search(std::string input)
{
    _exitCount = 0;
    displayAllContact();
    if (_nbContact > 0)
        displayContact(validIndex(input));
}

PhoneBook       *PhoneBook::exit()
{
    *this = PhoneBook();
    _exitCount++;

    return this;
}

std::string     PhoneBook::uppercase(std::string str)
{
    if (str != "")
        for (std::size_t i = 0; i < str.size(); i++)
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32; // 'a' - 'A'
    return str;
}

void            PhoneBook::handleInput(std::string input)
{
    if (uppercase(input) != "ADD" && 
        uppercase(input) != "SEARCH" &&
        uppercase(input) != "EXIT")
            std::cout << "Bad input, choose command: ADD | SEARCH | EXIT" << std::endl;
}

Contact         PhoneBook::fillContact(Contact contact, std::string str)
{
    std::cout << "Enter First Name:" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    contact.setFirstName(str);
    std::cout << "Enter Last Name:" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    contact.setLastName(str);
    std::cout << "Enter Nickname:" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    contact.setNickName(str);
    std::cout << "Enter Phone number:" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    contact.setPhoneNb(str);
    std::cout << "Enter Darkest secret:" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    contact.setDarkestSecret(str);
    
    return contact;
}

void            PhoneBook::runProcess(void)
{
    Contact         contact;
    bool            flag = true;

    while (flag == true)
    {
        if (std::getline(std::cin, _input))
        {
            handleInput(_input);            
            if (uppercase(_input) == "ADD")
                addContact(fillContact(contact, _input));
            else if (uppercase(_input) == "SEARCH")
                search(_input);
            else if (uppercase(_input) == "EXIT")
            {
                _exitCount++;
                if ((_exitCount % 2) != 0)
                    exit();                    
                else
                    flag = false;
            }
        }
    }
}

void            PhoneBook::process(void)
{
    std::cout << "PHONEBOOK starting..." << std::endl;
    std::cout << "Choose command: ADD | SEARCH | EXIT" << std::endl;
    runProcess();
    std::cout << "Program end" << std::endl;    
}
