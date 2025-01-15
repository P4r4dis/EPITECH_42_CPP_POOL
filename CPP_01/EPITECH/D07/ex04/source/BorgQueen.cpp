/*
** BorgQueen.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Sat Oct 19 3:35:26 PM 2024 Paradis
** Last update Sun Oct 19 3:53:02 PM 2024 Paradis
*/

#include "../include/BorgQueen.hpp"

Borg::BorgQueen::BorgQueen()    :   movePtr(&Borg::Ship::move),
                                    firePtr(&Borg::Ship::fire),
                                    destroyPtr(&Borg::Ship::fire)
{
}

Borg::BorgQueen::~BorgQueen()
{
}

void    Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    (ship->*firePtr)(target);
}

void    Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    (ship->*destroyPtr)(target);
}

bool    Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return (ship->*movePtr)(dest);
}