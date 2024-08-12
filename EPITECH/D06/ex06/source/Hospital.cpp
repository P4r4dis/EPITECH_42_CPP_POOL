/*
** Hospital.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 6:04:39 PM 2024 Paradis
** Last update Tue Aug 12 6:14:36 PM 2024 Paradis
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
	if (this->_koalaDoctorList && this->_koalaDoctorList->getFromName(doctorList->getContent()->getName()))
    {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
		return ;
    }
    
    if (!_koalaDoctorList)
        _koalaDoctorList = doctorList;
    else if (_koalaDoctorList)
        _koalaDoctorList->append(doctorList);

    std::cout << "[HOSPITAL] Doctor " << doctorList->getContent()->getName() << " just arrived!" << std::endl;
    doctorList->getContent()->timeCheck();
}


void                Hospital::addSick(SickKoalaList *sickKoalaList)
{
	if (this->_sickKoalaList && this->_sickKoalaList->getFromName(sickKoalaList->getContent()->getName()))
    {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
		return ;
    }
    
    if (!_sickKoalaList)
        _sickKoalaList = sickKoalaList;
    else if (_sickKoalaList)
        _sickKoalaList->append(sickKoalaList);

    std::cout << "[HOSPITAL] Patient " << sickKoalaList->getContent()->getName() << " just arrived!" << std::endl;
}

void                Hospital::addNurse(KoalaNurseList *koalaNurseList)
{
	if (this->_koalaNurseList && this->_koalaNurseList->getFromID(koalaNurseList->getContent()->getId()))
    {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
		return ;
    }
    
    if (!_koalaNurseList)
        _koalaNurseList = koalaNurseList;
    else if (_koalaNurseList)
        _koalaNurseList->append(koalaNurseList);

    std::cout << "[HOSPITAL] Nurse " << koalaNurseList->getContent()->getId() << " just arrived!" << std::endl;
    koalaNurseList->getContent()->timeCheck();
}