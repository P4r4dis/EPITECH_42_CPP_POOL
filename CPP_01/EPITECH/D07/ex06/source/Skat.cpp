/*
** Skat.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:23:03 PM 2025 Paradis
** Last update Fri Jan 30 7:46:44 PM 2025 Paradis
*/

#include "../include/Skat.hpp"
#include <string>

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