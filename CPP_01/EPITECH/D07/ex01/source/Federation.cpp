/*
** Federation.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:17:29 PM 2024 Paradis
** Last update Thu Sep 25 5:03:21 PM 2024 Paradis
*/

#include "../include/Federation.hpp"
#include <iostream>
#include <string>
Federation::Starfleet::Ship::Ship(
    int length, int width, std::string name, short maxWarp)
    :   _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
    std::cout   << "The ship USS " << _name << " has been finished."
                << std::endl << "It is " << _length
                << " m in length and " << _width << " m in width."
                << std::endl << "It can go to Warp " << _maxWarp << "!"
                << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void        Federation::Starfleet::Ship::setupCore(WarpSystem::Core *coreReactor)
{
    _coreReactor = coreReactor;
    if (_coreReactor)
        std::cout   << "USS " << _name << ": The core is set." << std::endl;
    else
        std::cerr   << "USS " << _name << ": The core is not set." << std::endl;
}

void        Federation::Starfleet::Ship::checkCore(void)
{
    if (_coreReactor)
    {
        if (_coreReactor->checkReactor()->isStable())
            std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
        else
            std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
    }
}
///////////////////////////////////////////////////////////////////////////////
Federation::Starfleet::Captain::Captain(std::string name)   :   _name(name),
                                                                _age(0)
{}

Federation::Starfleet::Captain::~Captain(void)
{}

std::string Federation::Starfleet::Captain::getName(void) const
{
    return _name;
}

int         Federation::Starfleet::Captain::getAge(void) const
{
    return _age;
}

void        Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

///////////////////////////////////////////////////////////////////////////////

Federation::Ship::Ship(int length, int width, std::string name)
    :   _length(length), _width(width), _name(name), _maxWarp(1)
{
    std::cout   << "The independent ship " << _name << " just finished its construction."
                << std::endl << "It is " << _length
                << " m in length and " << _width << " m in width."
                << std::endl;
}

Federation::Ship::~Ship()
{
}

short       Federation::Ship::getMaxWarp(void) const
{
    return _maxWarp;
}

void        Federation::Ship::setupCore(WarpSystem::Core *coreReactor)
{
    _coreReactor = coreReactor;
    if (_coreReactor)
        std::cout   << _name << ": The core is set." << std::endl;
    else
        std::cerr   << _name << ": The core is not set." << std::endl;
}

void        Federation::Ship::checkCore(void)
{
    if (_coreReactor)
    {
        if (_coreReactor->checkReactor()->isStable())
            std::cout << _name << ": The core is stable at the time." << std::endl;
        else
            std::cout << _name << ": The core is unstable at the time." << std::endl;
    }
}
