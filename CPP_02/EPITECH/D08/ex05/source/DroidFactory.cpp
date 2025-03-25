/*
** DroidFactory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:29:54 PM 2025 Paradis
** Last update Wed Mar 25 5:51:26 PM 2025 Paradis
*/

#include "../include/DroidFactory.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>

DroidFactory::DroidFactory(size_t ratio)    :   _ratio(ratio),
                                                _Iron(0),
                                                _Silicon(0),
                                                _Wreck(0),
                                                _exp(0)
{
}

DroidFactory::DroidFactory(const DroidFactory &dFactory)
                                            :   _ratio(dFactory._ratio),
                                                _Iron(dFactory._Iron),
                                                _Silicon(dFactory._Silicon),
                                                _Wreck(dFactory._Wreck),
                                                _exp(dFactory._exp)
{}

DroidFactory::~DroidFactory()
{
}

DroidFactory    &DroidFactory::operator=(const DroidFactory &dFactory)
{

    if (this == &dFactory)
    {
        std::cerr << "Error: Avoid self assignment." << std::endl;
        return *this;
    }
    else
    {
        _ratio = dFactory._ratio;
        _Iron = dFactory._Iron;
        _Silicon = dFactory._Silicon;
        _Wreck = dFactory._Wreck;
    }

    return *this;
}

Droid       *DroidFactory::operator>>(Droid *&droid)
{
    if (_Iron >= 100 && _Silicon >= 50)
    {
        _Iron -= 100;
        _Silicon -= 50;
        droid = new Droid("");
        droid->getBattleData()->setExp(_exp - (_exp / _ratio));
        
        return droid;
    }
    else
    {
        droid = nullptr;
        return droid;
    }
}

DroidFactory    &DroidFactory::operator<<(Supply &supply)
{
    switch (supply.getType())
    {
        case Supply::Iron:
            _Iron += supply.getAmount();
            break;
        case Supply::Silicon:
            _Silicon += supply.getAmount();
            break;
        case Supply::Wreck:
        {
            if (supply.getPtrWreck())
            {
                _Wreck = supply.getAmount();
                for (size_t i = 0; i < supply.getNbDroid(); ++i)
                {
                    if (supply.getPtrWreck()[i])
                    {
                        _Iron += IRON_COST;
                        _Silicon += SILICON_COST;
                        if (supply.getPtrWreck()[i]->getBattleData()->getExp() > _exp)
                            _exp += (supply.getPtrWreck()[i]->getBattleData()->getExp() - _exp) / _ratio;
                        else 
                            _exp += (_exp + supply.getPtrWreck()[i]->getBattleData()->getExp()) / _ratio;
                        delete supply.getPtrWreck()[i];
                        supply.getPtrWreck()[i] = nullptr;
                    }
                }
            }
            break;
        }
    }
    return *this;
}

size_t      DroidFactory::getRatio(void) const
{
    return  _ratio;
}

size_t      DroidFactory::getIron(void) const
{
    return  _Iron;
}

size_t      DroidFactory::getSilicon(void) const
{
    return  _Silicon;
}

size_t      DroidFactory::getWreck(void) const
{
    return  _Wreck;
}

size_t      DroidFactory::getExp(void) const
{
    return _exp;
}

void        DroidFactory::setIron(size_t iron)
{
    _Iron = iron;
}

void        DroidFactory::setSilicon(size_t silicon)
{
    _Silicon = silicon;
}

std::ostream    &operator<<(std::ostream &os, const DroidFactory &dFactory)
{
    os  << "DroidFactory status report :" << std::endl
        << "Iron : " << dFactory.getIron() << std::endl
        << "Silicon : " << dFactory.getSilicon() << std::endl
        << "Exp : " << dFactory.getExp() << std::endl
        << "End of status report.";
    return os;
}

// Supply &DroidFactory::operator>>(Supply &supply) {
//     if (supply.getType() == Supply::Wreck) {
//         *this << supply;
//     }
//     return supply;
// }