/*
** Raspberry.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:35:57 PM 2025 Paradis
** Last update Wed Jun 3 2:38:24 PM 2025 Paradis
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
