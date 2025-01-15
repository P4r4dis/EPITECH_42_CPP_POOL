/*
** Admiral.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Oct 3 3:46:31 PM 2024 Paradis
** Last update Thu Jan 15 7:08:45 PM 2025 Paradis
*/

#include "../include/Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name)  
    :   _name(name),
        movePtr(&Federation::Starfleet::Ship::move),
        firePtr(&Federation::Starfleet::Ship::fire)
{
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral(void)
{
}

void    Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship,
                                                            Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    (ship->*firePtr)(target);
}

bool    Federation::Starfleet::Admiral::move(
    Federation::Starfleet::Ship *ship, Destination dest)
{
    return (ship->*movePtr)(dest);
}
