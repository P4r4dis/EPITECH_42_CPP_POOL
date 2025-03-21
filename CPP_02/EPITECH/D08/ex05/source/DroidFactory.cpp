/*
** DroidFactory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:29:54 PM 2025 Paradis
** Last update Sat Mar 21 5:35:27 PM 2025 Paradis
*/

#include "../include/DroidFactory.hpp"
#include <iostream>

DroidFactory::DroidFactory(size_t ratio)    :   _ratio(ratio),
                                                _Iron(0),
                                                _Silicon(0),
                                                _Wreck(0)
{
}

DroidFactory::DroidFactory(const DroidFactory &dFactory)
                                            :   _ratio(dFactory._ratio),
                                                _Iron(dFactory._Iron),
                                                _Silicon(dFactory._Silicon),
                                                _Wreck(dFactory._Wreck)
{}

DroidFactory::~DroidFactory()
{
}

DroidFactory    &DroidFactory::operator=(const DroidFactory &dFactory)
{

    if (this == &dFactory)
    {
        std::cerr << "Error: Avoid self assignment." << std::endl;
        return *this;
    }
    else
    {
        _ratio = dFactory._ratio;
        _Iron = dFactory._Iron;
        _Silicon = dFactory._Silicon;
        _Wreck = dFactory._Wreck;
    }

    return *this;
}
size_t      DroidFactory::getRatio(void) const
{
    return  _ratio;
}

size_t      DroidFactory::getIron(void) const
{
    return  _Iron;
}

size_t      DroidFactory::getSilicon(void) const
{
    return  _Silicon;
}

size_t      DroidFactory::getWreck(void) const
{
    return  _Wreck;
}