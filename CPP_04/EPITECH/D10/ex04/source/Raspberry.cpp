/*
** Raspberry.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:35:57 PM 2025 Paradis
** Last update Fri Jun 5 9:13:26 PM 2025 Paradis
*/



#include "../include/Raspberry.hpp"

Raspberry::Raspberry(void)  :   ABerry("raspberry", 5)
{
}

Raspberry::Raspberry(const std::string& name, unsigned int vitamins, bool peeled)
    :   ABerry(name, vitamins, peeled)
{
}

Raspberry               &Raspberry::operator=(const Raspberry& raspberry)
{
    if (this != &raspberry)
    {
        _vitamins = raspberry._vitamins;
        _name = raspberry._name;
        _peeled = raspberry._peeled;
    }
    return *this;
}

Raspberry::~Raspberry()
{
}

Raspberry::Raspberry(const Raspberry &raspberry)    :   ABerry(raspberry._name,
                                                        raspberry._vitamins,
                                                        raspberry._peeled)
{
    if (this != &raspberry)
    {
        _vitamins = raspberry._vitamins;
        _name = raspberry._name;
        _peeled = raspberry._peeled;
    }
}

Raspberry              *Raspberry::clone(void) const
{
    return (new Raspberry(*this));
}