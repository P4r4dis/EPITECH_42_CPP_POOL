/*
** Carrier.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:15:28 PM 2025 Paradis
** Last update Fri Mar 20 7:15:48 PM 2025 Paradis
*/

#include "../include/Carrier.hpp"
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

size_t          Carrier::getNbDroid(void)
{
    NbDroid = 0;
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if (Droids[i] != nullptr)
            NbDroid++;
    }
    return NbDroid;
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
        updateSpeed();
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
            updateSpeed();
            return *this;
        }
    }
    return *this;
}

Carrier         &Carrier::operator>>(Droid *&droid)
{

    for (size_t i = 0; i < MAX_SIZE; ++i)
    {
        if (Droids[i])
        {
            droid = Droids[i];
            Droids[i] = nullptr;
            updateSpeed();
            return *this;
        }
    }
    return *this;
}

Droid           *&Carrier::operator[](size_t index)
{
    if (index < MAX_SIZE)
        return Droids[index];

    Droids[index] = nullptr;
    return Droids[index];
  
}

void            Carrier::updateSpeed(void)
{
    size_t count = 0;
    for (size_t i = 0; i < MAX_SIZE; ++i) {
        if (Droids[i] != nullptr)
            count++;
    }
    Speed = (count > 0) ? 100 - (count * 10) : 0;
}

Carrier         &Carrier::operator~(void)
{
    updateSpeed();
    return *this;
}

bool            Carrier::operator()(int x, int y)
{
    size_t costEnergy = ((std::abs(x) + std::abs(y)) * (10 + getNbDroid()));
    if (Energy < costEnergy || Speed == 0)
        return false;
    else
    {
        Energy -= costEnergy;
        return true;
    }
}

std::ostream    &operator<<(std::ostream &os, Carrier &carrier)
{
    os  << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        os  << "[" << i << "] : ";
        if (carrier[i])
            os << *carrier[i] << std::endl;
        else
            os << "Free" << std::endl;
    }
    os  << "Speed : " << carrier.getSpeed() << ", Energy " 
        << carrier.getEnergy();
    return os;
}