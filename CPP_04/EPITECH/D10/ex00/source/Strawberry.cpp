/*
** Strawberry.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 5:54:03 PM 2025 Paradis
** Last update Thu May 28 6:21:26 PM 2025 Paradis
*/

#include "../include/Strawberry.hpp"

Strawberry::Strawberry(void)  :   ABerry("strawberry", 6)
{
}

Strawberry::Strawberry(const std::string& name, unsigned int vitamins, bool peeled)
    :   ABerry(name, vitamins, peeled)
{
}

Strawberry               &Strawberry::operator=(const Strawberry& strawberry)
{
    if (this != &strawberry)
    {
        _vitamins = strawberry._vitamins;
        _name = strawberry._name;
        _peeled = strawberry._peeled;
    }
    return *this;
}

Strawberry::~Strawberry()
{
}
