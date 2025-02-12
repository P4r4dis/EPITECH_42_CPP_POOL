/*
** Skat.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 3:56:39 PM 2025 Paradis
** Last update Thu Feb 12 9:51:37 PM 2025 Paradis
*/



#include <iostream>
#include "../include/Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks, int serial, int x, int y,
            Phaser::AmmoType type)
                                :   _name(name),
                                    _stimPaks(stimPaks),
                                    _serial(serial),
                                    _x(x), _y(y),
                                    _type(type),
                                    _KreogCom(new KreogCom(_x, _y, _serial)),
                                    _Phaser(new Phaser(AMMUNITION, _type))

{
}

Skat::~Skat()
{
    if (_KreogCom)
        delete _KreogCom;
    if (_Phaser)
        delete _Phaser;
}

const std::string   &Skat::name(void)
{
    return _name;
}

int                 &Skat::stimPaks(void)
{
    return _stimPaks;
}

void                Skat::shareStimPaks(int number, int &stock)
{
    if (number >= _stimPaks)
        std::cout << "Don't be greedy" << std::endl;
    else
    {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void                Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        _stimPaks += number;
}

void                Skat::addStimPaks(int number)
{
    if (number < 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        addStimPaks(static_cast<unsigned int>(number));
}

void                Skat::useStimPaks(void)
{
    if (_stimPaks > 0)
    {
        _stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
    else
        std::cout << "Mediiiiiic" << std::endl;
}

void                Skat::status(void)
{
    std::cout   << "Soldier " + _name + " reporting " 
                << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

int                 Skat::getSkatSerial(void) const
{
    return _serial;
}

int                 Skat::getSkatX(void) const
{
    return _x;
}

int                 Skat::getSkatY(void) const
{
    return _y;
}

Phaser::AmmoType    Skat::getSkatType(void) const
{
    return _type;
}

KreogCom            *Skat::getPtrKreogCom(void) const
{
    return _KreogCom;
}

Phaser              *Skat::getPtrPhaser(void) const
{
    return _Phaser;
}

void                Skat::fire(void)
{
    _Phaser->fire();
}

void                Skat::locate(void)
{
    _KreogCom->ping();
}