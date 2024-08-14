/*
** KoalaNurse.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:34 PM 2024 Paradis
** Last update Thu Jul 31 4:56:37 PM 2024 Paradis
*/

#include <iostream>
#include <fstream>

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

std::string KoalaNurse::readReport(std::string fileName)
{
    std::fstream    fs;
    std::string     drug = "";
    std::string     namePatient = fileName;
    
    namePatient = namePatient.substr(0, namePatient.find(".report"));
    fs.open(fileName.c_str(), std::fstream::in);
    if (fs.is_open())
    {
        while(std::getline(fs, drug, '\0')) ;
        if (!namePatient.empty() && !drug.empty())
            std::cout   << "Nurse " << _id << ": Kreog! Mr."
                        << namePatient << " needs a " << drug << "!"
                        << std::endl;
        fs.close();
        return drug;
    }
    else
        return drug;
}