/*
** KoalaNurseList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:26:09 PM 2024 Paradis
** Last update Sat Aug 9 5:26:11 PM 2024 Paradis
*/


#include "KoalaNurseList.hpp"
#include <iostream>
KoalaNurseList::KoalaNurseList(KoalaNurse *koalaNurse)  :   _koalaNurse(koalaNurse),
                                                            _next(NULL)
{
}

KoalaNurseList::~KoalaNurseList(void)
{
}

KoalaNurse       *KoalaNurseList::getContent(void) const
{
    return _koalaNurse;
}

KoalaNurseList   *KoalaNurseList::getNext(void) const
{
    return _next;
}

KoalaNurse       *KoalaNurseList::getFromID(int koalaNurseID) const
{
    const KoalaNurseList   *current = this;

    while (current)
    {
        if (current->_koalaNurse->getId() == koalaNurseID)
            return current->_koalaNurse;
        current = current->_next;
    }
    return NULL;
}

bool            KoalaNurseList::isEnd(void)
{
    return (_next == NULL);
}

void            KoalaNurseList::append(KoalaNurseList *nodeList) 
{
    // 1: Verify if the nodeList is null
    if (nodeList == NULL) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    // 2: If the current nodeList's _koalaNurse->_name is null, replace it with the new nodeList's _koalaNurse->_name
    if (_koalaNurse == NULL) {
        _koalaNurse = nodeList->_koalaNurse;
        _next = nodeList->_next;
        return; // Early return after copying _koalaNurse->_name
    }

    // 3: Traverse the list to find the last nodeList and check for duplicates
    KoalaNurseList *current = this;
    while (current->_next != NULL) {
        if (current->_koalaNurse == nodeList->_koalaNurse) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return; // Prevent appending duplicates
        }
        current = current->_next;
    }

    // 4: Check the last nodeList for duplicate before adding
    if (current->_koalaNurse == nodeList->_koalaNurse) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    // 5: Add the new nodeList (nodeList) to the end of the list
    current->_next = nodeList;
    nodeList->_next = NULL;

}

KoalaNurseList* KoalaNurseList::remove(KoalaNurseList *nodeList) 
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
            this->_koalaNurse = NULL;
            return this;
        } 
        else
        {
            this->_koalaNurse = NULL;
            this->_next = nodeList->_next;
            return this;
        }
    }

    KoalaNurseList* current = this;
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

KoalaNurseList   *KoalaNurseList::removeFromID(int koalaNurseID)
{
    // Special case: removing the head node
    if (this->_koalaNurse && this->_koalaNurse->getId() == koalaNurseID) {
        if (this->_next == NULL) {
            this->_koalaNurse = NULL;
            return this;
        } else {
            this->_koalaNurse = NULL;
            // this->_koalaNurse = this->_next->_koalaNurse;
            // this->_next = this->_next->_next;
            return this;
        }
    }

    KoalaNurseList* current = this;
    while (current->_next != NULL) {
        if (current->_next->_koalaNurse && current->_next->_koalaNurse->getId() == koalaNurseID) {
            KoalaNurseList* nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;
            nodeToRemove->_next = NULL;
            return this;
        }
        current = current->_next;
    }

    return this;
}

void            KoalaNurseList::dump(void)
{
    KoalaNurseList   *current = this;
    
    std::cout << "Nurses: " << std::flush;
    while (current)
    {
        if (current->_koalaNurse)
            std::cout << current->_koalaNurse->getId() << std::flush;
        else
            std::cout << "[nullptr]" << std::flush;
        if (current->_next)
            std::cout << ", " << std::flush;
        else
            std::cout << "."  << std::endl;
        current = current->_next;
    }
}