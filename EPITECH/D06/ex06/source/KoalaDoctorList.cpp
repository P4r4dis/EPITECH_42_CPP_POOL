/*
** KoalaDoctorList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:25:49 PM 2024 Paradis
** Last update Wed Aug 13 3:56:36 PM 2024 Paradis
*/


#include "KoalaDoctorList.hpp"
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
    // 1: Verify if the nodeList is null
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    // 2: If the current nodeList's _koalaDoctor->_name is null, replace it with the new nodeList's _koalaDoctor->_name
    if (_koalaDoctor == NULL) {
        _koalaDoctor = nodeList->_koalaDoctor;
        _next = nodeList->_next;
        return; // Early return after copying _koalaDoctor->_name
    }

    // 3: Traverse the list to find the last nodeList and check for duplicates
    KoalaDoctorList *current = this;
    while (current->_next != NULL) {
        if (current->_koalaDoctor == nodeList->_koalaDoctor) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return; // Prevent appending duplicates
        }
        current = current->_next;
    }

    // 4: Check the last nodeList for duplicate before adding
    if (current->_koalaDoctor == nodeList->_koalaDoctor) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    // 5: Add the new nodeList (nodeList) to the end of the list
    current->_next = nodeList;
    nodeList->_next = NULL;

}

KoalaDoctorList* KoalaDoctorList::remove(KoalaDoctorList *nodeList) 
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
    // // Special case: removing the head node
    // if (this->_koalaDoctor && this->_koalaDoctor->getName() == koalaDoctorName) {
    //     if (this->_next == NULL) {
    //         this->_koalaDoctor = NULL;
    //         return this;
    //     } else {
    //         this->_koalaDoctor = NULL;
    //         // this->_koalaDoctor = this->_next->_koalaDoctor;
    //         // this->_next = this->_next->_next;
    //         return this;
    //     }
    // }

    // KoalaDoctorList* current = this;
    // while (current->_next != NULL) {
    //     if (current->_next->_koalaDoctor && current->_next->_koalaDoctor->getName() == koalaDoctorName) {
    //         KoalaDoctorList* nodeToRemove = current->_next;
    //         current->_next = nodeToRemove->_next;
    //         nodeToRemove->_next = NULL;
    //         return this;
    //     }
    //     current = current->_next;
    // }

    // return this;

// Cas spécial : suppression du noeud tête
    if (this->_koalaDoctor && this->_koalaDoctor->getName() == koalaDoctorName) {
        if (this->_next == nullptr) {
            // Si c'est le seul noeud de la liste
            this->_koalaDoctor = nullptr;
            return nullptr; // Liste maintenant vide
        } else {
            // Si la liste contient plusieurs noeuds
            this->_koalaDoctor = this->_next->_koalaDoctor;
            this->_next = this->_next->_next;
            return this; // Retourner la nouvelle tête de la liste
        }
    }

    // Parcourir la liste pour trouver le noeud à supprimer
    KoalaDoctorList* current = this;
    while (current->_next != nullptr) {
        if (current->_next->_koalaDoctor && current->_next->_koalaDoctor->getName() == koalaDoctorName) {
            current->_next = current->_next->_next; // Bypasser le noeud à supprimer
            return this; // Retourner la tête de la liste
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