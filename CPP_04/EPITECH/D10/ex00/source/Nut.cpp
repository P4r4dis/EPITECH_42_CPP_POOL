/*
** Nut.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:07:28 PM 2025 Paradis
** Last update Thu May 28 6:08:20 PM 2025 Paradis
*/

#include "../include/Nut.hpp"

Nut::Nut(void)  :   ANut("Nut", 2)
{
}

Nut::Nut(const std::string& name, unsigned int vitamins, bool peeled)
    :   ANut(name, vitamins, peeled)
{
}

Nut               &Nut::operator=(const Nut& nut)
{
    if (this != &nut)
    {
        _vitamins = nut._vitamins;
        _name = nut._name;
        _peeled = nut._peeled;
    }
    return *this;
}

Nut::~Nut()
{
}
