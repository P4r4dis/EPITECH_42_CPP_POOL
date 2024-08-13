/*
** KoalaDoctor.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:41 PM 2024 Paradis
** Last update Wed Aug 13 5:22:01 PM 2024 Paradis
*/


#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../include/KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)  :   _name(name),
                                                _timeCheck(false)
{
    std::cout   << "Dr." << _name << ": I'm Dr." 
                << _name << "! How do you kreog?"
                << std::endl;
}

KoalaDoctor::~KoalaDoctor(void)
{
}

std::string         KoalaDoctor::getName(void) const
{
    return _name;
}

bool                KoalaDoctor::getTimeCheck(void) const
{
    return _timeCheck;
}

void                KoalaDoctor::timeCheck(void)
{
    _timeCheck = !_timeCheck;
    if (_timeCheck)
        std::cout   << "Dr." << _name << ": Time to get to work!"
                    << std::endl;
    else
        std::cout   << "Dr." << _name 
                    << ": Time to go home to my eucalyptus forest!"
                    << std::endl;
}

void                KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string     nameFile = patient->getName() + ".report";
    std::ofstream   report(nameFile.c_str());
    
    std::cout   << "Dr." << _name << ": So what's goerking you Mr." 
                << patient->getName() << "?" << std::endl;
    patient->poke();
    if (report.is_open())
    {
        std::string  drug[5] = {"Mars", "Kinder", "Crunch", "Maroilles"
                                                    , "Eucalyptus leaf"};
        report << drug[random() % 5];
        report.close();
    }
    return ;
}