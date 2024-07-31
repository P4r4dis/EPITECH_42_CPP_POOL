/*
** SickKoalaList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:58 PM 2024 Paradis
** Last update Thu Jul 31 10:17:29 PM 2024 Paradis
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

bool            SickKoalaList::isEnd(void)
{
    return (_next == nullptr);
}

void            SickKoalaList::append(SickKoalaList *nodeList)
{
    if (nodeList == nullptr)
    {
        std::cerr << "Error: Trying to append a null node." << std::endl;
        return ;
    }

    if (_sickKoala == nullptr)
    {
        _sickKoala = nodeList->_sickKoala;
        _next = nodeList->_next;
        // clean nodeList;
        nodeList->_sickKoala = nullptr;
        nodeList->_next = nullptr;
    }
    else
    {
        for (SickKoalaList *current = this; current; current = current->_next)
        {
            if (current->_sickKoala == nodeList->_sickKoala)
            {
                std::cerr << "Error: Trying to append a duplicate node." << std::endl;
                return ;
            }
            if (current->_next == nullptr)
            {
                current->_next = nodeList;
                return;
            }
        }
    }
}