/*
** Borg.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Sep 24 7:19:34 PM 2024 Paradis
** Last update Fri Sep 26 5:37:25 PM 2024 Paradis
*/

#include "../include/Borg.hpp"
#include <iostream>

Borg::Ship::Ship(void)  :   _side(300), _maxWarp(9), _coreReactor(nullptr),
                            _home(UNICOMPLEX), _location(_home)
{
    std::cout   << "We are the Borgs. "
                << "Lower your shields and surrender yourselves unconditionally."
                << std::endl
                << "Your biological characteristics and technologies will be assimilated."
                << std::endl
                << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship(void)
{
}

void        Borg::Ship::setupCore(WarpSystem::Core *coreReactor)
{
    if (coreReactor)
        _coreReactor = coreReactor;
    else
        std::cerr << "Borg ship: The core is not set." << std::endl;
}

void        Borg::Ship::checkCore(void)
{
    if (_coreReactor)
    {
        if (_coreReactor->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }
    else
        std::cout << "Critical failure imminent." << std::endl;
}


Destination Borg::Ship::getLocation(void) const
{
    return _location;
}

bool        Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && _location != d &&
        (_coreReactor && _coreReactor->checkReactor()->isStable()))
    {
        _location = d;
        return true;
    }
    else
        return false;
}

bool        Borg::Ship::move(int warp)
{
    return move(warp, _home);
}

bool        Borg::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool        Borg::Ship::move(void)
{
    return move(_maxWarp, _home);
}