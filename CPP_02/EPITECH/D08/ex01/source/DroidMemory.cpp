/*
** DroidMemory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Mar 3 6:16:16 PM 2025 Paradis
** Last update Tue Mar 3 6:32:40 PM 2025 Paradis
*/

#include "../include/DroidMemory.hpp"
#include <iostream>

DroidMemory::DroidMemory(void)  :   Fingerprint(random()), Exp(0)
{
    std::cout << "DroidMemory '" << Fingerprint << "', " << Exp << std::endl;
}

DroidMemory::DroidMemory(const DroidMemory &copyCTOR)
                    :   Fingerprint(copyCTOR.Fingerprint), Exp(copyCTOR.Exp)
{
    std::cout << "DroidMemory '" << Fingerprint << "', " << Exp << std::endl;
}


DroidMemory::~DroidMemory(void)
{
}

DroidMemory         &DroidMemory::operator=(const DroidMemory &rhs)
{
    if (this != &rhs)
    {
        Fingerprint = rhs.Fingerprint;
        Exp = rhs.Exp;
        return *this;
    }
    else
        return *this;
}

size_t              DroidMemory::getFingerPrint(void) const
{
    return Fingerprint;
}

size_t              DroidMemory::getExp(void) const
{
    return Exp;
}

void                DroidMemory::setFingerPrint(size_t fingerprint)
{
    Fingerprint = fingerprint;
}

void                DroidMemory::setExp(size_t exp)
{
    Exp = exp;
}