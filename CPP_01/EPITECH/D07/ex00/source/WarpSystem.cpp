/*
** WarpSystem.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:32:25 PM 2024 Paradis
** Last update Tue Sep 23 6:01:00 PM 2024 Paradis
*/

#include "../include/WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void)    :   _stability(true)
{
}


WarpSystem::QuantumReactor::~QuantumReactor(void)
{
}


bool        WarpSystem::QuantumReactor::isStable(void) const
{
    return _stability;
}

void        WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}