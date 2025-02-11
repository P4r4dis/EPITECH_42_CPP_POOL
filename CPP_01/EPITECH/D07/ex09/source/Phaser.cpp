/*
** Phaser.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 9:24:41 PM 2025 Paradis
** Last update Wed Feb 11 4:05:37 PM 2025 Paradis
*/

#include "../include/Phaser.hpp"
#include <iostream>

const int Phaser::Empty = 0;

const std::string Sounds::Regular = "Piouuuuuu";
const std::string Sounds::Plasma = "Fiouuuuuz";
const std::string Sounds::Rocket = "Booooooom";

Phaser::Phaser(int maxAmmo, AmmoType type)
                                        :   _maxAmmo(maxAmmo),
                                            _nbAmmos(_maxAmmo),
                                            _type(type),
                                            _magazine(new AmmoType[_maxAmmo])
{
    for (int i = 0; i < _maxAmmo; ++i)
    {
        std::cout << i << std::endl;
        _magazine[i] = _type;
    }
}

Phaser::~Phaser()
{
    if (_magazine)
        delete [] _magazine;
}

int                 Phaser::getNbAmmos(void) const
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