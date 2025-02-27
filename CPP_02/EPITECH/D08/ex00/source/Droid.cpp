/*
** Droid.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Feb 27 4:59:15 PM 2025 Paradis
** Last update Fri Feb 27 6:37:39 PM 2025 Paradis
*/
#include <cstddef>
#include <iostream>
#include <string>

#include "../include/Droid.hpp"

Droid::Droid(void)  :   Id(ID), Energy(ENERGY), Attack(ATTACK),
                        Toughness(TOUGHNESS), Status(new std::string(STATUS))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(std::string serial)    :   Id(serial), Energy(ENERGY),
                                        Attack(ATTACK), Toughness(TOUGHNESS),
                                        Status(new std::string(STATUS))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copyCTOR) :   Id(copyCTOR.Id),
                                        Energy(copyCTOR.Energy),
                                        Attack(copyCTOR.Attack),
                                        Toughness(copyCTOR.Toughness),
                                        Status(new std::string(*copyCTOR.Status))
{
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (Status)
    {
        delete Status;
        Status = nullptr;
    }
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

Droid               &Droid::operator=(const Droid &droid)
{
    if (this != &droid)
    {
        Id = droid.Id;
        Energy = droid.Energy;
        if (Status)
        {
            delete Status;
            Status = nullptr;
            Status = new std::string(*droid.Status);
        }
        return *this;
    }
    else
        return *this;
}

std::string         Droid::getId(void) const
{
    return Id;
}

size_t              Droid::getEnergy(void) const
{
    return Energy;
}

size_t              Droid::getAttack(void) const
{
    return Attack;
}

size_t              Droid::getToughness(void) const
{
    return Toughness;
}

std::string         *Droid::getStatus(void) const
{
    return Status;
}