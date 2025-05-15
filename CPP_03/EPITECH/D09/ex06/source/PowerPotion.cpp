/*
** PowerPotion.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 5:49:54 PM 2025 Paradis
** Last update Fri May 15 6:37:32 PM 2025 Paradis
*/

#include "../include/PowerPotion.hpp"


PowerPotion::PowerPotion(void)    :   _PP(50)
{
}

PowerPotion::~PowerPotion(void)
{
}

int     PowerPotion::getValuePotion(void) const
{
    return _PP;
}

int     PowerPotion::getStatusPotion(void) const
{
    return POWER_POTION;
}