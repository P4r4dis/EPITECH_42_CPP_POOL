/*
** Strawberry.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 5:54:03 PM 2025 Paradis
** Last update Fri Jun 5 9:14:18 PM 2025 Paradis
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

Strawberry::Strawberry(const Strawberry &strawberry)    :   
                                                    ABerry(strawberry._name,
                                                    strawberry._vitamins,
                                                    strawberry._peeled)
{
    if (this != &strawberry)
    {
        _vitamins = strawberry._vitamins;
        _name = strawberry._name;
        _peeled = strawberry._peeled;
    }
}

Strawberry              *Strawberry::clone(void) const
{
    return (new Strawberry(*this));
}