/*
** SickKoalaList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:58 PM 2024 Paradis
** Last update Fri Aug 1 9:31:45 PM 2024 Paradis
*/

#include "SickKoalaList.hpp"
#include <iostream>
SickKoalaList::SickKoalaList(SickKoala *sickKoala)  :   _sickKoala(sickKoala),
                                                        _next(nullptr)
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
    return nullptr;
}

bool            SickKoalaList::isEnd(void)
{
    return (_next == nullptr);
}

void            SickKoalaList::append(SickKoalaList *nodeList) 
{
    // 1: Verify if the node is null
    if (nodeList == nullptr) {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return;
    }

    // 2: If the current node's data is null, replace it with the new node's data
    if (_sickKoala == nullptr) {
        _sickKoala = nodeList->_sickKoala;
        _next = nodeList->_next;
        return; // Early return after copying data
    }

    // 3: Traverse the list to find the last node and check for duplicates
    SickKoalaList *current = this;
    while (current->_next != nullptr) {
        if (current->_sickKoala == nodeList->_sickKoala) {
            std::cerr << "Error: Trying to append a duplicate node." << std::endl;
            return; // Prevent appending duplicates
        }
        current = current->_next;
    }

    // 4: Check the last node for duplicate before adding
    if (current->_sickKoala == nodeList->_sickKoala) {
        std::cerr << "Error: Trying to append a duplicate node." << std::endl;
        return;
    }

    // 5: Add the new node (nodeList) to the end of the list
    current->_next = nodeList;
    nodeList->_next = nullptr;
}


SickKoalaList   *SickKoalaList::remove(SickKoalaList *nodeList)
{
    // 1: Verify if the node is null
    if (nodeList == nullptr) {
        std::cerr << "Error: Trying to delete a null node." << std::endl;
        return this;
    }

    // Verify the first node is the same of the new nodeList to remove
    if (this == nodeList)
    {
        // clean  data
        _sickKoala = nullptr;
        // update the current pointer for point to next;
        _next = nodeList->_next;
        return this;
    }

    // 3. Through the list
    // init tempory ptr for trough the list
    SickKoalaList   *current = this;
    // scroll through the list until you find the corresponding node or reach the end of the list.
    while (current)
    {
        if (current == nodeList)
        {
            // clean data
            current->_sickKoala = nullptr;
            // update current next
            current->_next = nodeList->_next;
        }
        current = current->_next;
    }
    return this;
}