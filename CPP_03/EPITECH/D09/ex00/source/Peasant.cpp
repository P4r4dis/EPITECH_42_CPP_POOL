/*
** Peasant.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 6 5:38:49 PM 2025 Paradis
** Last update Wed May 6 7:00:38 PM 2025 Paradis
*/

#include "../include/Peasant.hpp"
#include <iostream>
#include <string>

Peasant::Peasant(void)  :   _name("Unknown"), _power(0), _hp(100)
{
    std::cout   << "A peasant with no name or power points is like a pony "
                << "that isn't pink: nonsense." << std::endl;
}

Peasant::Peasant(const std::string &name, int power)    :   _name(name),
                                                            _hp(100)
{
    if (power < 0)
        _power = 0;
    else if (power > 100)
        _power = 100;
    else
        _power = power;

    std::cout   << _name << " goes for an adventure." << std::endl;
}

Peasant::Peasant(const Peasant &obj)    :   _name(obj._name),
                                            _power(obj._power),
                                            _hp(obj._hp)
{
    std::cout   << _name << " goes for an adventure." << std::endl;
}

Peasant             &Peasant::operator=(const Peasant &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }

    return *this;
}

Peasant::~Peasant(void)
{
    std::cout   << _name << " is back to his crops." << std::endl;
}

const std::string   &Peasant::getName(void) const
{
    return _name;
}

void                Peasant::setName(const std::string &name)
{
    _name = name;
}

int                 Peasant::getPower(void) const
{
    return _power;
}

void                Peasant::setPower(int power)
{
    if (power < 0)
        _power = 0;
    else if (power > 100)
        _power = 100;
    else
        _power = power;
}

int                 Peasant::getHp(void) const
{
    return _hp;
}

void                Peasant::setHp(int hp)
{
    if (hp < 0)
        _hp = 0;
    else if (hp > 100)
        _hp = 100;
    else
        _hp = hp;
}