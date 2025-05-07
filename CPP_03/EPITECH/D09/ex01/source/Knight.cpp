/*
** Knight.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:29:24 PM 2025 Paradis
** Last update Thu May 7 8:12:26 PM 2025 Paradis
*/

#include "../include/Knight.hpp"
#include <iostream>

Knight::Knight(void)
{
    _name = "";
    _power = 0;
    _hp = 100;
    std::cout   << "A knight with no name or power points is like a pony "
                << "that isn't pink: nonsense." << std::endl;
}

Knight::Knight(const std::string &name, int power)  :   Peasant(name, power)
{
    _name = name;
    power > 100 ? _power = 100 : power < 0 ? _power = 0 : _power = power;
    _hp = 100;
    if (_name.empty() || _power == 0)
        std::cout   << "A knight with no name or power points is like a pony "
                    << "that isn't pink: nonsense." << std::endl;
    else
        std::cout   << _name << " vows to protect the kingdom." << std::endl;
}

Knight::Knight(const Knight &obj)   :   Peasant(obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }
    std::cout   << _name << " vows to protect the kingdom." << std::endl;
}

Knight              &Knight::operator=(const Knight &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }

    return *this;
}

Knight::~Knight()
{
    if (_name.empty())
        std::cout   << "Unknown takes off his armor." << std::endl;
    else
        std::cout   << _name << " takes off his armor." << std::endl;
}

int                 Knight::attack(void)
{
    int     cost = 10;
    int     damage = 20;

    if (_hp == 0)
    {
        std::cout   << _name << " is out of combat." << std::endl;
        return 0;
    }
    else if (_power < cost)
    {
        std::cout   << _name << " is out of power." << std::endl;
        return 0;
    }
    else
    {
        _power -= cost;
        std::cout   << _name << " strikes with his sword." << std::endl;
        return damage;
    }
}

int                 Knight::special(void)
{
    int     cost = 30;
    int     damage = 50;

    if (_hp == 0)
    {
        std::cout   << _name << " is out of combat." << std::endl;
        return 0;
    }
    else if (_power <= cost)
    {
        std::cout   << _name << " is out of power." << std::endl;
        return 0;
    }
    else
    {
        _power -= cost;
        std::cout   << _name << " impales his enemy." << std::endl;
        return damage;
    }
}

void                Knight::rest(void)
{
    int     cost = 0;
    int     rest = 50;

    if (_hp == 0)
        std::cout   << _name << " is out of combat." << std::endl;
    else if (_power <= cost)
        std::cout   << _name << " is out of power." << std::endl;
    else
    {
        _power = (_power + rest > 100) ? 100 : _power + rest;
        std::cout   << _name << " eats." << std::endl;
    }
}
