/*
** Skat.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:23:03 PM 2025 Paradis
** Last update Tue Feb 3 9:06:39 PM 2025 Paradis
*/

#include "../include/Skat.hpp"
#include <iostream>

Skat::Skat(const std::string &name, int stimPaks)   :   _name(name),
                                                        _stimPaks(stimPaks)
{
}

Skat::~Skat()
{
}

const std::string   &Skat::name(void)
{
    return _name;
}

int                 &Skat::stimPaks(void)
{
    return _stimPaks;
}

void                Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimPaks)
        std::cout << "Don't be greedy" << std::endl;
    else
    {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}