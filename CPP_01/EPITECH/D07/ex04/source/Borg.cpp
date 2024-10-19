/*
** Borg.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Sep 24 7:19:34 PM 2024 Paradis
** Last update Thu Oct 2 6:09:21 PM 2024 Paradis
*/

#include "../include/Borg.hpp"
#include <iostream>

Borg::Ship::Ship(int weaponFrequency, short repair)
                :   _side(300), _maxWarp(9), _coreReactor(nullptr),
                    _home(UNICOMPLEX), _location(_home),
                    _shield(100), _weaponFrequency(weaponFrequency),
                    _repair(repair)
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

int         Borg::Ship::getShield(void) const
{
    return _shield;
}

int         Borg::Ship::getWeaponFrequency(void) const
{
    return _weaponFrequency;
}

short       Borg::Ship::getRepair(void) const
{
    return _repair;
}

void        Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

void        Borg::Ship::setWeaponFrequency(int weaponFrequency)
{
    _weaponFrequency = weaponFrequency;
}

void        Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void        Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - _weaponFrequency);
    if (target->getShield() < 0)
         target->setShield(0);
    std::cout   << "Firing on target with " << _weaponFrequency
                << "GW frequency." << std::endl;
}

void        Borg::Ship::fire(Federation::Ship *target)
{
    std::cout   << "Firing on target with " << _weaponFrequency
                << "GW frequency." << std::endl;
    target->getCore()->checkReactor()->setStability(false);
}

void        Borg::Ship::repair(void)
{
    if (_repair > 0)
    {
        _shield = 100;
        _repair--;
        std::cout   << "Begin shield re-initialisation... "
                    << "Done. Awaiting further instructions."
                    << std::endl;
    }
    else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}