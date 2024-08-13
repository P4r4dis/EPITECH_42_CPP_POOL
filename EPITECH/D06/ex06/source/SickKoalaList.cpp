/*
** SickKoalaList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:26:20 PM 2024 Paradis
** Last update Wed Aug 13 3:33:13 PM 2024 Paradis
*/



#include "SickKoalaList.hpp"
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
    // 1: Verify if the nodeList is null
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    // 2: If the current nodeList's _sickKoala->_name is null, replace it with the new nodeList's _sickKoala->_name
    if (_sickKoala == NULL) {
        _sickKoala = nodeList->_sickKoala;
        _next = nodeList->_next;
        return; // Early return after copying _sickKoala->_name
    }

    // 3: Traverse the list to find the last nodeList and check for duplicates
    SickKoalaList *current = this;
    while (current->_next != NULL) {
        if (current->_sickKoala == nodeList->_sickKoala) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return; // Prevent appending duplicates
        }
        current = current->_next;
    }

    // 4: Check the last nodeList for duplicate before adding
    if (current->_sickKoala == nodeList->_sickKoala) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    // 5: Add the new nodeList (nodeList) to the end of the list
    current->_next = nodeList;
    nodeList->_next = NULL;

}

SickKoalaList* SickKoalaList::remove(SickKoalaList *nodeList) 
{
    // 1. Vérifier si le noeud à supprimer est nul
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





// Cas spécial : suppression du noeud tête
    if (this->_sickKoala && this->_sickKoala->getName() == sickKoalaName) {
        if (this->_next == nullptr) {
            // Si c'est le seul noeud de la liste
            this->_sickKoala = nullptr;
            return nullptr; // Liste maintenant vide
        } else {
            // Si la liste contient plusieurs noeuds
            this->_sickKoala = this->_next->_sickKoala;
            this->_next = this->_next->_next;
            return this; // Retourner la nouvelle tête de la liste
        }
    }

    // Parcourir la liste pour trouver le noeud à supprimer
    SickKoalaList* current = this;
    while (current->_next != nullptr) {
        if (current->_next->_sickKoala && current->_next->_sickKoala->getName() == sickKoalaName) {
            current->_next = current->_next->_next; // Bypasser le noeud à supprimer
            return this; // Retourner la tête de la liste
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
            std::cout << "[nullptr]" << std::flush;
        if (current->_next)
            std::cout << ", " << std::flush;
        else
            std::cout << "."  << std::endl;
        current = current->_next;
    }
}