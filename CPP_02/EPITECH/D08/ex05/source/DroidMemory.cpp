/*
** DroidMemory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:16:26 PM 2025 Paradis
** Last update Fri Mar 20 7:16:42 PM 2025 Paradis
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

DroidMemory         &DroidMemory::operator>>(DroidMemory &lhs)
{
    lhs.Exp += Exp;
    lhs.Fingerprint ^= Fingerprint;
    
    return lhs;
}

DroidMemory         DroidMemory::operator+(const DroidMemory &rhs)
{
    DroidMemory newDroidMemory(*this);

    newDroidMemory.Exp += rhs.Exp;
    newDroidMemory.Fingerprint ^= rhs.Fingerprint;
    
    return newDroidMemory;
}

std::ostream        &operator<<(std::ostream &os, const DroidMemory &rhs)
{
    os << "DroidMemory '" << rhs.getFingerPrint() << "', " << rhs.getExp();
    return os;
}

DroidMemory         &DroidMemory::operator+=(const DroidMemory &lhs)
{
    return *this << lhs;
}

bool                DroidMemory::operator==(const DroidMemory &rhs)
{
    return (Exp == rhs.Exp) && (Fingerprint == rhs.Fingerprint);
}

bool                DroidMemory::operator!=(const DroidMemory &rhs)
{
    return !(*this == rhs);
}

bool                DroidMemory::operator<(const DroidMemory &rhs)
{
    return Exp < rhs.Exp;
}

bool                DroidMemory::operator>(const DroidMemory &rhs)
{
    return  Exp > rhs.Exp;
}

bool                DroidMemory::operator<=(const DroidMemory &rhs)
{
    return Exp <= rhs.Exp;
}

bool                DroidMemory::operator>=(const DroidMemory &rhs)
{
    return Exp >= rhs.Exp;
}

bool                DroidMemory::operator<(const size_t &rhs)
{
    return Exp < rhs;
}

bool                DroidMemory::operator<=(const size_t &rhs)
{
    return Exp <= rhs;
}

bool                DroidMemory::operator>(const size_t &rhs)
{
    return Exp > rhs;
}

bool                DroidMemory::operator>=(const size_t &rhs)
{
    return Exp >= rhs;
}