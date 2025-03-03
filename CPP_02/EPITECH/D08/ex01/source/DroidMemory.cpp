/*
** DroidMemory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Mar 3 6:16:16 PM 2025 Paradis
** Last update Tue Mar 3 9:27:39 PM 2025 Paradis
*/

#include "../include/DroidMemory.hpp"
#include <iostream>
#include <ostream>

DroidMemory::DroidMemory(void)  :   Fingerprint(random()), Exp(0)
{
}

DroidMemory::DroidMemory(const DroidMemory &copyCTOR)
                    :   Fingerprint(copyCTOR.Fingerprint), Exp(copyCTOR.Exp)
{
}


DroidMemory::~DroidMemory(void)
{
        delete this;
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

DroidMemory         &DroidMemory::operator+=(const size_t &rhs)
{
    Exp += rhs;
    Fingerprint ^= rhs;
    return *this;
}

DroidMemory         &DroidMemory::operator<<(const DroidMemory &lhs)
{
    Exp += lhs.Exp;
    Fingerprint ^= lhs.Fingerprint;
    return *this;
}

DroidMemory         &DroidMemory::operator>>(DroidMemory &rhs)
{
    rhs.Exp += Exp;
    rhs.Fingerprint ^= Fingerprint;
    return rhs;
}

DroidMemory         &DroidMemory::operator+(const DroidMemory &rhs)
{
    DroidMemory *newDroidMemory = new DroidMemory(*this);
    newDroidMemory->Fingerprint = newDroidMemory->Fingerprint ^ rhs.Fingerprint;
    newDroidMemory->Exp = newDroidMemory->Exp + rhs.Exp;

    return *newDroidMemory;
}

std::ostream        &operator<<(std::ostream &os, const DroidMemory &rhs)
{
    os << "DroidMemory '" << rhs.getFingerPrint() << "', " << rhs.getExp();
    return os;
}