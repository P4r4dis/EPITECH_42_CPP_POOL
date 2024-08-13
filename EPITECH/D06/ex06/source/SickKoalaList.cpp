/*
** SickKoalaList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:26:20 PM 2024 Paradis
** Last update Wed Aug 13 5:36:21 PM 2024 Paradis
*/



#include "../include/SickKoalaList.hpp"
#include <iostream>
SickKoalaList::SickKoalaList(SickKoala *sickKoala)  :   _sickKoala(sickKoala),
                                                        _next(NULL)
{
}

SickKoalaList::~SickKoalaList(void)
{
}

SickKoala       *SickKoalaList::getContent(void) const
{
    return _sickKoala;
}

SickKoalaList   *SickKoalaList::getNext(void) const
{
    return _next;
}

SickKoala       *SickKoalaList::getFromName(std::string SickKoalaName) const
{
    const SickKoalaList   *current = this;

    while (current)
    {
        if (current->_sickKoala->getName() == SickKoalaName)
            return current->_sickKoala;
        current = current->_next;
    }
    return NULL;
}

bool            SickKoalaList::isEnd(void)
{
    return (_next == NULL);
}

void            SickKoalaList::append(SickKoalaList *nodeList) 
{
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    if (_sickKoala == NULL) {
        _sickKoala = nodeList->_sickKoala;
        _next = nodeList->_next;
        return;
    }

    SickKoalaList *current = this;
    while (current->_next != NULL) {
        if (current->_sickKoala == nodeList->_sickKoala) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return;
        }
        current = current->_next;
    }

    if (current->_sickKoala == nodeList->_sickKoala) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    current->_next = nodeList;
    nodeList->_next = NULL;

}

SickKoalaList* SickKoalaList::remove(SickKoalaList *nodeList) 
{
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to delete a null node." << std::endl;
        return this;
    }

    if (this == nodeList)
    {
        if (this->_next == NULL)
        {
            this->_sickKoala = NULL;
            return this;
        } 
        else
        {
            this->_sickKoala = NULL;
            this->_next = nodeList->_next;
            return this;
        }
    }

    SickKoalaList* current = this;
    while (current->_next != NULL)
    {
        if (current->_next == nodeList)
        {
            current->_next = nodeList->_next;
            nodeList->_next = NULL;
            return this;
        }
        current = current->_next;
    }
    return this;
}

SickKoalaList   *SickKoalaList::removeFromName(std::string sickKoalaName)
{

    if (this->_sickKoala && this->_sickKoala->getName() == sickKoalaName) {
        if (this->_next == NULL) {

            this->_sickKoala = NULL;
            return NULL;
        } else {

            this->_sickKoala = this->_next->_sickKoala;
            this->_next = this->_next->_next;
            return this;
        }
    }

    SickKoalaList* current = this;
    while (current->_next != NULL) {
        if (current->_next->_sickKoala && current->_next->_sickKoala->getName() == sickKoalaName) {
            current->_next = current->_next->_next;
            return this;
        }
        current = current->_next;
    }

    return this;
}



void            SickKoalaList::dump(void)
{
    SickKoalaList   *current = this;
    
    std::cout << "Patients: " << std::flush;
    while (current)
    {
        if (current->_sickKoala)
            std::cout << current->_sickKoala->getName() << std::flush;
        else
            std::cout << "[NULL]" << std::flush;
        if (current->_next)
            std::cout << ", " << std::flush;
        else
            std::cout << "."  << std::endl;
        current = current->_next;
    }
}