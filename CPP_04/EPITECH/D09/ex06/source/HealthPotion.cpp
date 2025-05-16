/*
** HealthPotion.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 4:33:44 PM 2025 Paradis
** Last update Fri May 15 6:29:43 PM 2025 Paradis
*/

#include "../include/HealthPotion.hpp"

HealthPotion::HealthPotion(void)    :   _HP(50)
{
}

HealthPotion::~HealthPotion(void)
{
}

int     HealthPotion::getValuePotion(void) const
{
    return _HP;
}

int     HealthPotion::getStatusPotion(void) const
{
    return HEALTH_POTION;
}