/*
** KoalaBot.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 3:42:52 PM 2025 Paradis
** Last update Wed Feb 4 4:34:23 PM 2025 Paradis
*/

#include "../include/KoalaBot.hpp"
#include <string>

KoalaBot::KoalaBot(std::string serial)  :   _serial(serial),
                                            _arms(new Arms),
                                            _legs(new Legs),
                                            _head(new Head)

{
}

KoalaBot::~KoalaBot()
{
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