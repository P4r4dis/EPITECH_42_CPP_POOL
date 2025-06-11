/*
** AFruit.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 5:24:21 PM 2025 Paradis
** Last update Fri Jun 5 7:52:44 PM 2025 Paradis
*/

#include "../include/AFruit.hpp"

AFruit::AFruit(const std::string& name, unsigned int vitamins, bool peeled)
            :   _vitamins(vitamins),
                _name(name),
                _peeled(peeled)
{}

AFruit::AFruit(const AFruit &aFruit)    :   _vitamins(aFruit._vitamins),
                                            _name(aFruit._name),
                                            _peeled(aFruit._peeled)
{
    if (this != &aFruit)
    {
        _vitamins = aFruit._vitamins;
        _name = aFruit._name;
        _peeled = aFruit._peeled;
    }
}

unsigned int        AFruit::getVitamins(void) const
{
    return _peeled ? _vitamins : 0;
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
    if (!_peeled)
        _peeled = true;
}

AFruit              *AFruit::clone(void) const
{
    return (new AFruit(*this));
}
