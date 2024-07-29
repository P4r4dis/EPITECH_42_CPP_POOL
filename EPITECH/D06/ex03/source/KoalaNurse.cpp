/*
** KoalaNurse.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:40:33 PM 2024 Paradis
** Last update Tue Jul 29 8:23:28 PM 2024 Paradis
*/
#include <iostream>

#include "../include/KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)  : _id(id), _timeToWork(false)
{
}

KoalaNurse::~KoalaNurse(void)
{
    _timeToWork = false;
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

int         KoalaNurse::getId(void) const
{
    return _id;
}

bool        KoalaNurse::getTimeToWork(void) const
{
    return _timeToWork;
}


void        KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

void        KoalaNurse::timeCheck(void)
{
    _timeToWork = !_timeToWork;
    if (_timeToWork)
        std::cout   << "Nurse " << _id << ": Time to get to work!"
                    << std::endl;
    else
        std::cout   << "Nurse " << _id
                    << ": Time to go home to my eucalyptus forest!"
                    << std::endl;
}