/*
** KoalaBot.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 3:42:52 PM 2025 Paradis
** Last update Wed Feb 4 7:01:06 PM 2025 Paradis
*/

#include "../include/KoalaBot.hpp"
#include <iostream>
#include <string>

KoalaBot::KoalaBot(std::string serial)  :   _serial(serial),
                                            _arms(new Arms),
                                            _legs(new Legs),
                                            _head(new Head)

{
}

KoalaBot::~KoalaBot()
{
    if (_arms)
        delete _arms;
    if (_legs)
        delete _legs;
    if (_head)
        delete _head;
}

std::string     KoalaBot::getSerial(void) const
{
    return _serial;
}

Arms            *KoalaBot::getArms(void) const
{
    return _arms;
}

Legs            *KoalaBot::getLegs(void) const
{
    return _legs;
}

Head            *KoalaBot::getHead(void) const
{
    return _head;
}


void            KoalaBot::setParts(Arms &arms)
{
    *_arms = arms;
}

void            KoalaBot::setParts(Legs &legs)
{
    *_legs = legs;
}

void            KoalaBot::setParts(Head &head)
{
    *_head = head;
}

void            KoalaBot::swapParts(Arms &arms)
{
    std::swap(*_arms, arms);
}

void            KoalaBot::swapParts(Legs &legs)
{
    std::swap(*_legs, legs);
}

void            KoalaBot::swapParts(Head &head)
{
    std::swap(*_head, head);
}

void            KoalaBot::informations(void)
{
    std::cout   << "[KoalaBot] " << _serial << std::endl;
    _arms->informations();
    _legs->informations();
    _head->informations();
}