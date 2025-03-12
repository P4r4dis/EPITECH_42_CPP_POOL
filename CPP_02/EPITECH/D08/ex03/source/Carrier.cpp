/*
** Carrier.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 11 6:31:41 PM 2025 Paradis
** Last update Thu Mar 12 8:11:14 PM 2025 Paradis
*/

#include "../include/Carrier.hpp"
#include <cstddef>
#include <string>

Carrier::Carrier(std::string id)    :   Id(id), Energy(300), Attack(100),
                                        Toughness(90), Speed(0)
{
    for(size_t i = 0; i < MAX_SIZE; ++i)
        Droids[i] = nullptr;
}

Carrier::~Carrier(void)
{
    for (size_t i = 0; i < MAX_SIZE; ++i)
    {
        if (Droids[i])
        {
            delete Droids[i];
            Droids[i] = nullptr;
        }
    }
}

std::string     Carrier::getId(void) const
{
    return Id;
}

size_t          Carrier::getEnergy(void) const
{
    return Energy;
}

size_t          Carrier::getAttack(void) const
{
    return Attack;
}

size_t          Carrier::getToughness(void) const
{
    return Toughness;
}

size_t          Carrier::getSpeed(void) const
{
    return Speed;
}

Droid          *Carrier::getDroids(size_t nb) const
{
    if (nb < 5)
        return Droids[nb];
    else
        return nullptr;
}

void            Carrier::setId(std::string id)
{
    Id = id;
}

void            Carrier::setEnergy(size_t energy)
{
    Energy = energy;
}

void            Carrier::setSpeed(size_t speed)
{
    Speed = speed;
}

void            Carrier::setDroids(size_t pos, Droid *droid)
{
    if (pos < MAX_SIZE && Droids[pos] != droid)
    {
        if (Droids[pos])
            delete Droids[pos];
        Droids[pos] = droid;

        Speed = 100;
        size_t nbDroid = 0;
        for (size_t i = 0; i < MAX_SIZE; ++i)
        {
            if (Droids[i] != nullptr)
                nbDroid++;
        }
        Speed -= 10 * nbDroid;
    }
}

Carrier         &Carrier::operator<<(Droid *&droid)
{
    if (droid == nullptr)
        return *this;

    for (size_t i = 0; i < MAX_SIZE; ++i)
    {
        if (!Droids[i])
        {

            Droids[i] = droid;
            droid = nullptr;
            // size_t nbDroid = 0;
            // for (size_t i = 0; i < MAX_SIZE; ++i)
            // {
            //     if (Droids[i] != nullptr)
            //         nbDroid++;
            // }
            Speed = 100 - (10 * (i + 1));//nbDroid);
            return *this;
        }
    }
    return *this;
}