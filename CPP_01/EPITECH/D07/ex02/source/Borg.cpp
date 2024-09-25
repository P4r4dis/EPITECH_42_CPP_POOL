/*
** Borg.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Sep 24 7:19:34 PM 2024 Paradis
** Last update Thu Sep 25 8:08:23 PM 2024 Paradis
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