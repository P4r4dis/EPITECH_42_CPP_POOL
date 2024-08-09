/*
** Hospital.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 6:04:39 PM 2024 Paradis
** Last update Sat Aug 9 9:31:44 PM 2024 Paradis
*/

#include <iostream>
#include "../include/Hospital.hpp"

Hospital::Hospital(void)    :   _sickKoalaList(NULL),
                                _koalaNurseList(NULL),
                                _koalaDoctorList(NULL)
{
}

Hospital::~Hospital(void)
{
}

SickKoalaList       *Hospital::getSickKoalaList(void) const
{
    return _sickKoalaList;
}

KoalaNurseList      *Hospital::getKoalaNurseList(void) const
{
    return _koalaNurseList;
}

KoalaDoctorList      *Hospital::getKoalaDoctorList(void) const
{
    return _koalaDoctorList;
}

void                Hospital::addDoctor(KoalaDoctorList *doctorList)
{

    if (!_koalaDoctorList)
        _koalaDoctorList = doctorList;
    else if (_koalaDoctorList)
        _koalaDoctorList->append(doctorList);

    std::cout << "[HOSPITAL] Doctor " << doctorList->getContent()->getName() << " just arrived!" << std::endl;
    doctorList->getContent()->timeCheck();
}


void                Hospital::addSick(SickKoalaList *sickKoalaList)
{

    if (!_sickKoalaList)
        _sickKoalaList = sickKoalaList;
    else if (_sickKoalaList)
        _sickKoalaList->append(sickKoalaList);

    std::cout << "[HOSPITAL] Patient " << sickKoalaList->getContent()->getName() << " just arrived!" << std::endl;
}
