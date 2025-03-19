/*
** Supply.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 18 6:14:24 PM 2025 Paradis
** Last update Thu Mar 19 10:41:39 PM 2025 Paradis
*/

#include "../include/Supply.hpp"
#include <cstddef>
#include <ostream>

Supply::Supply(Types type, size_t Amount)
        :   _type(type), _amount(Amount), 
            _wreck((_type == Supply::Wreck) ? new Droid *[_amount] : nullptr),
            _nbDroids((_type == Supply::Wreck) ? _amount : 0)
{}

Supply::Supply(Types type, size_t Amount, Droid **Wreck)    
                :   _type(type), _amount(Amount), _wreck(Wreck),
                    _nbDroids((_type == Supply::Wreck) ? _amount : 0)
{}

Supply::~Supply()
{
    if (_wreck)
    {
        for (size_t i = 0; i < _amount; ++i)
            if (_wreck[i])
            {
                delete _wreck[i];
                _wreck[i] = nullptr;
            }
        delete [] _wreck;
    }
}

Supply::Types       Supply::getType(void) const
{
    return _type;
}

size_t              Supply::getAmount(void) const
{
    return _amount;
}

Droid               **Supply::getPtrWreck(void) const
{
    return _wreck;
}

size_t              Supply::getNbDroid(void) const
{
    return _nbDroids;
}

std::ostream        &operator<<(std::ostream &os, const Supply &supply)
{
    os  << "Supply : " << supply.getAmount() << ", ";
    switch (supply.getType())
    {
        case 1:
            os << "Iron";
            break;
        case 2:
            os << "Silicon";
            break;
        case 3:
            os << "Wreck" << std::endl;
            for (size_t i = 0; i < supply.getNbDroid(); ++i)
                (i != supply.getNbDroid() - 1) ? 
                    os << *supply.getPtrWreck()[i] << std::endl :
                    os << *supply.getPtrWreck()[i];
            break;
    }
    return os;
}


Supply::operator    size_t(void) const
{
    return _amount;
}

Droid               *Supply::operator*(void)
{
    return _wreck[_nbDroids];
}

Supply              &Supply::operator--(void)
{
    _nbDroids = _nbDroids == 0 ? _amount : _nbDroids - 1;
    return *this;
}