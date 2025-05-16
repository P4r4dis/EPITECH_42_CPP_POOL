/*
** Enchanter.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:17:32 PM 2025 Paradis
** Last update Tue May 12 6:44:01 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Enchanter.hpp"

Enchanter::Enchanter(void)
{
    _name = "";
    _power = 0;
    _hp = 100;
    std::cout   << "A enchanter with no name or power points is like a pony "
                << "that isn't pink: nonsense." << std::endl;
}

Enchanter::Enchanter(const std::string &name, int power)  :   Peasant(name, power)
{
    _name = name;
    power > 100 ? _power = 100 : power < 0 ? _power = 0 : _power = power;
    _hp = 100;
    if (_name.empty() || _power == 0)
        std::cout   << "A enchanter with no name or power points is like a pony "
                    << "that isn't pink: nonsense." << std::endl;
    else
        std::cout   << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::Enchanter(const Enchanter &obj)   :   Peasant(obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }
    std::cout   << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter              &Enchanter::operator=(const Enchanter &obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _power = obj._power;
        _hp = obj._hp;
    }

    return *this;
}

Enchanter::~Enchanter()
{
    if (_name.empty())
        std::cout   << "Unknown closes his spellbook." << std::endl;
    else
        std::cout   << _name << " closes his spellbook." << std::endl;
}

int                 Enchanter::attack(void)
{
    int     cost = 0;
    int     damage = 0;

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
        std::cout   << _name << " doesn't know how to fight." << std::endl;
        return damage;
    }
}

int                 Enchanter::special(void)
{
    int     cost = 50;
    int     damage = 99;

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
        std::cout   << _name << " casts a fireball." << std::endl;
        return damage;
    }
}

void                Enchanter::rest(void)
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
        std::cout   << _name << " meditates." << std::endl;
    }
}
