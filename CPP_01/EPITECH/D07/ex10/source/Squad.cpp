/*
** Squad.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 7:49:34 PM 2025 Paradis
** Last update Sat Feb 14 2:16:55 PM 2025 Paradis
*/

#include "../include/Squad.hpp"
#include "../include/Sounds.hpp"

const std::string   Sounds::Regular = "Bang";
const std::string   Sounds::Plasma = "Fwooosh";
const std::string   Sounds::Rocket = "Booooooom";

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size)
            :   _posXBegin(posXBegin), _posYBegin(posYBegin),
                _ammoType(ammoType), _size(size), _Skat(new Skat *[_size + 1])
{
    for (int i = 0; i < _size; ++i)
        _Skat[i] = new Skat("Junior " + std::to_string(i), 15, 
    i,i * POS_X_INCREMENT, i * POS_Y_INCREMENT,_ammoType);
    _Skat[_size] = nullptr;
}

Squad::~Squad()
{
    if (_Skat)
    {
        for (int i = 0; i < _size; ++i)
        {
            delete _Skat[i];
            _Skat[i] = nullptr;
        }
        delete [] _Skat;
        _Skat = nullptr;
    }
}

int                 Squad::getPosXBegin(void) const
{
    return _posXBegin;
}

int                 Squad::getPosYBegin(void) const
{
    return _posYBegin;
}

Phaser::AmmoType    Squad::getAmmoType(void) const
{
    return _ammoType;
}

Skat                **Squad::getPtrSkat(void) const
{
    return _Skat;
}

int                 Squad::size(void) const
{
    return _size;
}

void                Squad::foreach(int beginIdx,
                                    void (Skat::*actionPtr) (void))
{
    if (beginIdx < 0 || beginIdx > _size)
        return ;
    for (; beginIdx < _size; ++beginIdx)
        (*_Skat[beginIdx].*actionPtr)();
}