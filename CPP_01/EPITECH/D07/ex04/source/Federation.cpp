/*
** Federation.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Sep 26 7:07:13 PM 2024 Paradis
** Last update Thu Oct 2 7:40:16 PM 2024 Paradis
*/

#include "../include/Federation.hpp"
#include <iostream>
#include <string>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
    :   _length(length), _width(width), _name(name), _maxWarp(maxWarp),
        _captain(nullptr), _home(EARTH), _location(_home), _shield(100),
        _photonTorpedo(torpedo)
{
    std::cout   << "The ship USS " << _name << " has been finished."
                << std::endl << "It is " << _length
                << " m in length and " << _width << " m in width."
                << std::endl << "It can go to Warp " << _maxWarp << "!"
                << std::endl;
    if (_photonTorpedo > 0)
        std::cout   << "Weapons are set: " << _photonTorpedo 
                    << " torpedoes ready." << std::endl;
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

void        Federation::Starfleet::Ship::promote(Captain *captain)
{
    if (captain)
    {
        _captain = captain;
        std::cout   << _captain->getName() 
                    << ": I'm glad to be the captain of the USS "
                    << _name << "." << std::endl;
    }
    else
        std::cerr   << "Error: No Captain to promote." << std::endl;
}

std::string Federation::Starfleet::Ship::getName(void) const
{
    return _name;
}

Destination Federation::Starfleet::Ship::getLocation(void) const
{
    return _location;
}

short       Federation::Starfleet::Ship::getMaxWarp(void) const
{
    return _maxWarp;
}

bool        Federation::Starfleet::Ship::move(int warp, Destination d)
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

bool        Federation::Starfleet::Ship::move(int warp)
{
    return move(warp, _home);
}

bool        Federation::Starfleet::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool        Federation::Starfleet::Ship::move(void)
{
    return move(_maxWarp, _home);
}

int         Federation::Starfleet::Ship::getShield(void) const
{
    return _shield;
}

void        Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int         Federation::Starfleet::Ship::getTorpedo(void) const
{
    return _photonTorpedo;
}

void        Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

Federation::Starfleet::Captain      *Federation::Starfleet::Ship::getCaptain(void) const
{
    return _captain;
}

void        Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    fire(1, target);
}

void        Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_captain && target)
    {
        if (_photonTorpedo <= 0)
        {
            std::cout   << _name << ": No enough torpedoes to fire, "
                        << _captain->getName() << "!" << std::endl;
        }
        else if (_photonTorpedo > 0)
        {
            if (torpedoes > _photonTorpedo)
            {
                std::cout   << _name << ": No more torpedo to fire, "
                            << _captain->getName() << "!" << std::endl;     
                return ;
            }
            _photonTorpedo -= torpedoes;
            target->setShield(target->getShield() - (50 * torpedoes));
            if (target->getShield() < 0)
                target->setShield(0);

            std::cout   << _name << ": Firing on target. " 
                        << torpedoes <<  " torpedoes remaining."
                        << std::endl;
        }
    }
    else
        std::cerr   << "Error: Captain and target must be set, cannot be nullptr."
                    << std::endl;
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
Federation::Starfleet::Ensign::Ensign(std::string name) :   _name(name)
{
    std::cout   << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign(void)
{}
///////////////////////////////////////////////////////////////////////////////
Federation::Ship::Ship(int length, int width, std::string name)
    :   _length(length), _width(width), _name(name), _maxWarp(1),
        _coreReactor(nullptr), _home(VULCAN), _location(_home)
{
    std::cout   << "The independent ship " << _name << " just finished its construction."
                << std::endl << "It is " << _length
                << " m in length and " << _width << " m in width."
                << std::endl;
}

Federation::Ship::~Ship()
{
}

short               Federation::Ship::getMaxWarp(void) const
{
    return _maxWarp;
}

void                Federation::Ship::setupCore(WarpSystem::Core *coreReactor)
{
    _coreReactor = coreReactor;
    if (_coreReactor)
        std::cout   << _name << ": The core is set." << std::endl;
    else
        std::cerr   << _name << ": The core is not set." << std::endl;
}

void                Federation::Ship::checkCore(void)
{
    if (_coreReactor)
    {
        if (_coreReactor->checkReactor()->isStable())
            std::cout << _name << ": The core is stable at the time." << std::endl;
        else
            std::cout << _name << ": The core is unstable at the time." << std::endl;
    }
}

Destination         Federation::Ship::getLocation(void) const
{
    return _location;
}

bool                Federation::Ship::move(int warp, Destination d)
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

bool                Federation::Ship::move(int warp)
{
    return move(warp, _home);
}

bool                Federation::Ship::move(Destination d)
{
    return move(_maxWarp, d);
}

bool                Federation::Ship::move(void)
{
    return move(_maxWarp, _home);
}

WarpSystem::Core    *Federation::Ship::getCore(void) const
{
    return _coreReactor;
}
// Implement the following member functions for the Starfleet’s Ships:
// void fire(Borg::Ship *target);
// void fire(int torpedoes , Borg::Ship *target);

