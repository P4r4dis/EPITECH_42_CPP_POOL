/*
** Priest.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 7:05:34 PM 2025 Paradis
** Last update Wed May 13 4:39:47 PM 2025 Paradis
*/


#include <iostream>
#include "../include/Priest.hpp"

Priest::Priest(void)
{
    _name = "";
    _power = 0;
    _hp = 100;
    std::cout   << "A priest with no name or power points is like a pony "
                << "that isn't pink: nonsense." << std::endl;
}

Priest::Priest(const std::string &name, int power)  :   Peasant(name, power),
                                                        Enchanter(name, power)
{
    _name = name;
    power > 100 ? _power = 100 : power < 0 ? _power = 0 : _power = power;
    _hp = 100;
    if (_name.empty() || _power == 0)
        std::cout   << "A priest with no name or power points is like a pony "
                    << "that isn't pink: nonsense." << std::endl;
    else
        std::cout   << _name << " enters in the order." << std::endl;
}

Priest::Priest(const Priest &obj)   :   Peasant(obj), Enchanter(obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }
    std::cout   << _name << " enters in the order." << std::endl;
}

Priest              &Priest::operator=(const Priest &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }

    return *this;
}

Priest::~Priest()
{
    if (_name.empty())
        std::cout   << "Unknown finds peace." << std::endl;
    else
        std::cout   << _name << " finds peace." << std::endl;
}

void                Priest::rest(void)
{
    int     cost = 0;
    int     rest = 100;

    if (_hp == 0)
        std::cout   << _name << " is out of combat." << std::endl;
    else if (_power <= cost)
        std::cout   << _name << " is out of power." << std::endl;
    else
    {
        _power = (_power + rest > 100) ? 100 : _power + rest;
        _hp = (_hp + rest > 100) ? 100 : _hp + rest;
        std::cout   << _name << " prays." << std::endl;
    }
}
