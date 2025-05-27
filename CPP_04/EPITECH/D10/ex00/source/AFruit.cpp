/*
** AFruit.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 5:24:21 PM 2025 Paradis
** Last update Wed May 27 5:39:49 PM 2025 Paradis
*/

#include "../include/AFruit.hpp"

unsigned int        AFruit::getVitamins(void) const
{
    return _vitamins;
}

std::string         AFruit::getName(void) const
{
    return _name;
}

bool                AFruit::isPeeled(void) const
{
    return _peeled;
}

void                AFruit::peel()
{
    if (_peeled == false)
        _peeled = true;
}