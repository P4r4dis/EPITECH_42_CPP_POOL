/*
** Droid.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Mar 3 4:57:14 PM 2025 Paradis
** Last update Tue Mar 3 5:13:35 PM 2025 Paradis
*/


#include <iostream>
#include <string>

#include "../include/Droid.hpp"

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

void                Droid::setId(std::string id)
{
    Id = id;
}

void                Droid::setEnergy(size_t energy)
{
    energy > 100 ? Energy = 100 : Energy = energy;
}

void                Droid::setStatus(std::string *status)
{
    delete Status;
    Status = status;
}

std::ostream        &operator<<(std::ostream &os, Droid const &rhs)
{
    return os   << "Droid '" << rhs.getId() << "', "
                << rhs.getStatus()->data() << ", " << rhs.getEnergy();
}

Droid               &Droid::operator<<(size_t &rhs)
{

    if (Energy < 100)
    {
        size_t need = 100 - Energy;
        size_t reload = (rhs >= 100) ? need : rhs;

        Energy += reload;
        rhs -= reload;
    }
    return *this;
}

bool                Droid::operator==(const Droid &droid)
{
    return (Id == droid.Id && Energy == droid.Energy &&
            Attack == droid.Attack && Toughness == droid.Toughness &&
            *Status == *droid.Status);
}

bool                Droid::operator!=(const Droid &droid)
{
    return !(*this == droid);
}