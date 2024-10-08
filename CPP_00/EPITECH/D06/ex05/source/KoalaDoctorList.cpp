/*
** KoalaDoctorList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 8 6:44:06 PM 2024 Paradis
** Last update Thu Aug 14 3:36:44 PM 2024 Paradis
*/




#include "../include/KoalaDoctorList.hpp"
#include <iostream>
KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koalaDoctor)  :   _koalaDoctor(koalaDoctor),
                                                                _next(NULL)
{
}

KoalaDoctorList::~KoalaDoctorList(void)
{
}

KoalaDoctor       *KoalaDoctorList::getContent(void) const
{
    return _koalaDoctor;
}

KoalaDoctorList   *KoalaDoctorList::getNext(void) const
{
    return _next;
}

KoalaDoctor       *KoalaDoctorList::getFromName(std::string KoalaDoctorName) const
{
    const KoalaDoctorList   *current = this;

    while (current)
    {
        if (current->_koalaDoctor->getName() == KoalaDoctorName)
            return current->_koalaDoctor;
        current = current->_next;
    }
    return NULL;
}

bool            KoalaDoctorList::isEnd(void)
{
    return (_next == NULL);
}

void            KoalaDoctorList::append(KoalaDoctorList *nodeList) 
{
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    if (_koalaDoctor == NULL) {
        _koalaDoctor = nodeList->_koalaDoctor;
        _next = nodeList->_next;
        return;
    }

    KoalaDoctorList *current = this;
    while (current->_next != NULL) {
        if (current->_koalaDoctor == nodeList->_koalaDoctor) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return;
        }
        current = current->_next;
    }

    if (current->_koalaDoctor == nodeList->_koalaDoctor) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    current->_next = nodeList;
    nodeList->_next = NULL;

}

KoalaDoctorList* KoalaDoctorList::remove(KoalaDoctorList *nodeList) 
{
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to delete a null node." << std::endl;
        return this;
    }

    if (this == nodeList)
    {
        if (this->_next == NULL)
        {
            this->_koalaDoctor = NULL;
            return this;
        } 
        else
        {
            this->_koalaDoctor = NULL;
            this->_next = nodeList->_next;
            return this;
        }
    }

    KoalaDoctorList* current = this;
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

KoalaDoctorList   *KoalaDoctorList::removeFromName(std::string koalaDoctorName)
{
    if (this->_koalaDoctor && this->_koalaDoctor->getName() == koalaDoctorName) {
        if (this->_next == NULL) {
            this->_koalaDoctor = NULL;
            return this;
        } else {
            this->_koalaDoctor = NULL;
            return this;
        }
    }

    KoalaDoctorList* current = this;
    while (current->_next != NULL) {
        if (current->_next->_koalaDoctor && current->_next->_koalaDoctor->getName() == koalaDoctorName) {
            KoalaDoctorList* nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;
            nodeToRemove->_next = NULL;
            return this;
        }
        current = current->_next;
    }

    return this;
}

void            KoalaDoctorList::dump(void)
{
    KoalaDoctorList   *current = this;
    
    std::cout << "Doctors: " << std::flush;
    while (current)
    {
        if (current->_koalaDoctor)
            std::cout << current->_koalaDoctor->getName() << std::flush;
        else
            std::cout << "[nullptr]" << std::flush;
        if (current->_next)
            std::cout << ", " << std::flush;
        else
            std::cout << "."  << std::endl;
        current = current->_next;
    }
}