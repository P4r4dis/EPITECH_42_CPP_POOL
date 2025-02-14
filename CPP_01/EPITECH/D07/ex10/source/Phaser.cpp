/*
** Phaser.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 4:08:21 PM 2025 Paradis
** Last update Sat Feb 14 6:41:50 PM 2025 Paradis
*/

#include "../include/Phaser.hpp"
#include "../include/Sounds.hpp"

#include <iostream>

const int           Phaser::Empty = 0;

Phaser::Phaser(int maxAmmo, AmmoType type)
                                        :   _maxAmmo(maxAmmo),
                                            _nbAmmos(_maxAmmo),
                                            _type(type),
                                            _magazine(new AmmoType[_maxAmmo])
{
    for (int i = 0; i < _maxAmmo; ++i)
        _magazine[i] = _type;
}

Phaser::~Phaser()
{
    if (_magazine)
    {
        delete [] _magazine;
        _magazine = nullptr;
    }
}

int                 Phaser::getCurrentAmmos(void) const
{
    return _nbAmmos;
}

int                 Phaser::getMaxAmmo(void) const
{
    return _maxAmmo;
}

Phaser::AmmoType    Phaser::getType(void) const
{
    return _type;
}

int                 Phaser::getEmptyMagazine(void)
{
    return Empty;
}

Phaser::AmmoType    *Phaser::getMagazine(void) const
{
    return _magazine;
}

void                Phaser::fire(void)
{
    if (_nbAmmos == Empty)
    {
        std::cout << "Clip empty, please reload" << std::endl;
        return ;
    }

    switch (_magazine[_nbAmmos - 1])
    {
        case REGULAR:
            std::cout << Sounds::Regular << std::endl;
            break;
        case PLASMA:
            std::cout << Sounds::Plasma << std::endl;
            break;
        case ROCKET:
            std::cout << Sounds::Rocket << std::endl;
            break;
    }
    _nbAmmos--;
}

void                Phaser::ejectClip(void)
{
    if (_magazine)
    {
        delete [] _magazine;
        _magazine = nullptr;
        _nbAmmos = Empty;
    }
}

void                Phaser::changeType(AmmoType type)
{
    _type = type;
    std::cout << "Switching ammo to type: ";
    switch (_type)
    {
        case 0:
            std::cout << "regular" << std::endl;
            break;
        case 1:
            std::cout << "plasma" << std::endl;
            break;
        case 2:
            std::cout << "rocket" << std::endl;
            break;
    }
}

void                Phaser::reload(void)
{
    if (!_magazine)
        _magazine = new AmmoType[_maxAmmo];
    _nbAmmos = _maxAmmo;
    for (int i = 0; i < _maxAmmo; ++i)
        _magazine[i] = _type;
    std::cout << "Reloading..." << std::endl;
}

void                Phaser::addAmmo(AmmoType type)
{
    if (_nbAmmos >= _maxAmmo)
    {
        std::cout << "Clip full" << std::endl;
        return ;
    }

    _magazine[_nbAmmos++] = type;
}