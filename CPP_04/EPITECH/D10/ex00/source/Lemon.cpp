/*
** Lemon.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 9:23:34 PM 2025 Paradis
** Last update Thu May 28 5:40:28 PM 2025 Paradis
*/

#include "../include/Lemon.hpp"

Lemon::Lemon(void)  :   ACitrus("Lemon", 4)
{
}

Lemon::Lemon(const std::string& name, unsigned int vitamins, bool peeled)
    :   ACitrus(name, vitamins, peeled)
{
}

Lemon               &Lemon::operator=(const Lemon& lemon)
{
    if (this != &lemon)
    {
        _vitamins = lemon._vitamins;
        _name = lemon._name;
        _peeled = lemon._peeled;
    }
    return *this;
}

Lemon::~Lemon()
{
}
