/*
** Hospital.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 6:04:39 PM 2024 Paradis
** Last update Wed Aug 13 3:55:12 PM 2024 Paradis
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

void                Hospital::run(void)
{
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    if (_koalaDoctorList && _sickKoalaList && _koalaNurseList)
    {
        _koalaDoctorList->dump();
        _koalaNurseList->dump();
        _sickKoalaList->dump();
        
        _koalaDoctorList->getFromName("Cox")->diagnose(_sickKoalaList->getFromName("Ganepar"));
        _koalaNurseList->getFromID(1)->giveDrug(_koalaNurseList->getFromID(1)->readReport("Ganepar.report"), _sickKoalaList->getFromName("Ganepar"));
        _sickKoalaList->removeFromName("Ganepar");

        _koalaDoctorList->getFromName("House")->diagnose(_sickKoalaList->getFromName("Varia"));
        _koalaNurseList->getFromID(2)->giveDrug(_koalaNurseList->getFromID(2)->readReport("Varia.report"), _sickKoalaList->getFromName("Varia"));
        _sickKoalaList->removeFromName("Varia");

            _koalaDoctorList->getFromName("Boudur-Oulot")->diagnose(_sickKoalaList->getFromName("RedFace"));
        _koalaNurseList->getFromID(1)->giveDrug(_koalaNurseList->getFromID(1)->readReport("RedFace.report"), _sickKoalaList->getFromName("RedFace"));
        _sickKoalaList->removeFromName("RedFace");

        _koalaDoctorList->getFromName("Cox")->diagnose(_sickKoalaList->getFromName("Scarface"));
        _koalaNurseList->getFromID(2)->giveDrug(_koalaNurseList->getFromID(2)->readReport("Scarface.report"), _sickKoalaList->getFromName("Scarface"));
        _sickKoalaList->removeFromName("Scarface");

        _koalaDoctorList->getFromName("House")->diagnose(_sickKoalaList->getFromName("Falter"));
        _koalaNurseList->getFromID(1)->giveDrug(_koalaNurseList->getFromID(1)->readReport("Falter.report"), _sickKoalaList->getFromName("Falter"));
        _sickKoalaList->removeFromName("Falter");
        if (_sickKoalaList->isEnd())
        {
            _koalaNurseList->getFromID(1)->timeCheck();
            _koalaNurseList = _koalaNurseList->removeFromID(1);
            _koalaNurseList->getFromID(2)->timeCheck();
            _koalaNurseList = _koalaNurseList->removeFromID(2);

            _koalaDoctorList->getFromName("Cox")->timeCheck();
            _koalaDoctorList = _koalaDoctorList->removeFromName("Cox");
            _koalaDoctorList->getFromName("House")->timeCheck();
            _koalaDoctorList = _koalaDoctorList->removeFromName("House");
            _koalaDoctorList->getFromName("Boudur-Oulot")->timeCheck();
            _koalaDoctorList = _koalaDoctorList->removeFromName("Boudur-Oulot");
        }
    }
}