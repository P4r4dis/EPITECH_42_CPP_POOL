/*
** Almond.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:07:28 PM 2025 Paradis
** Last update Fri Jun 5 9:01:24 PM 2025 Paradis
*/

#include "../include/Almond.hpp"

Almond::Almond(void)  :   ANut("almond", 2)
{
}

Almond::Almond(const std::string& name, unsigned int vitamins, bool peeled)
    :   ANut(name, vitamins, peeled)
{
}

Almond::Almond(const Almond &almond)    :   ANut(almond._name,
                                        almond._vitamins,
                                        almond._peeled)
{
    if (this != &almond)
    {
        _vitamins = almond._vitamins;
        _name = almond._name;
        _peeled = almond._peeled;
    }
}

Almond               &Almond::operator=(const Almond& almond)
{
    if (this != &almond)
    {
        _vitamins = almond._vitamins;
        _name = almond._name;
        _peeled = almond._peeled;
    }
    return *this;
}

Almond::~Almond()
{
}

Almond              *Almond::clone(void) const
{
    return (new Almond(*this));
}
