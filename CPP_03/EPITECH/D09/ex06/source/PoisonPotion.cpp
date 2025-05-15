/*
** PoisonPotion.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 5:51:54 PM 2025 Paradis
** Last update Fri May 15 6:40:54 PM 2025 Paradis
*/

#include "../include/PoisonPotion.hpp"

PoisonPotion::PoisonPotion(void)    :   _poison(50)
{
}

PoisonPotion::~PoisonPotion(void)
{
}

int     PoisonPotion::getValuePotion(void) const
{
    return _poison;
}

int     PoisonPotion::getStatusPotion(void) const
{
    return POISON_POTION;
}