/*
** Paladin.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 7:45:00 PM 2025 Paradis
** Last update Tue May 12 7:52:15 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Paladin.hpp"

Paladin::Paladin(void)
{
    _name = "";
    _power = 0;
    _hp = 100;
    std::cout   << "A paladin with no name or power points is like a pony "
                << "that isn't pink: nonsense." << std::endl;
}

Paladin::Paladin(const std::string &name, int power)    :   Peasant(name, power),
                                                            Knight(name, power),
                                                            Priest(name, power)
{
    _name = name;
    power > 100 ? _power = 100 : power < 0 ? _power = 0 : _power = power;
    _hp = 100;
    if (_name.empty() || _power == 0)
        std::cout   << "A paladin with no name or power points is like a pony "
                    << "that isn't pink: nonsense." << std::endl;
    else
        std::cout   << _name << " fights for the light." << std::endl;
}

Paladin::Paladin(const Paladin &obj)    :   Peasant(obj),
                                            Knight(obj),
                                            Priest(obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }
    std::cout   << _name << " fights for the light." << std::endl;
}

Paladin              &Paladin::operator=(const Paladin &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }

    return *this;
}

Paladin::~Paladin()
{
    if (_name.empty())
        std::cout   << "Unknown is blessed." << std::endl;
    else
        std::cout   << _name << " is blessed." << std::endl;
}

int                 Paladin::attack(void)
{
    return Knight::attack();
}

int                 Paladin::special(void)
{
    return Enchanter::special();
}

void                Paladin::rest(void)
{
    return Priest::rest();
}
