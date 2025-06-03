/*
** Orange.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 9:28:22 PM 2025 Paradis
** Last update Thu May 28 6:21:21 PM 2025 Paradis
*/

#include "../include/Orange.hpp"

Orange::Orange(void)  :   ACitrus("orange", 7)
{
}

Orange::Orange(const std::string& name, unsigned int vitamins, bool peeled)
    :   ACitrus(name, vitamins, peeled)
{
}

Orange               &Orange::operator=(const Orange& orange)
{
    if (this != &orange)
    {
        _vitamins = orange._vitamins;
        _name = orange._name;
        _peeled = orange._peeled;
    }
    return *this;
}

Orange::~Orange()
{
}
