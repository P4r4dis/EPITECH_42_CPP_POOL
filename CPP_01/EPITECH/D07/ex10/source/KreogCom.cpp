/*
** KreogCom.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 3:57:52 PM 2025 Paradis
** Last update Fri Feb 13 4:29:33 PM 2025 Paradis
*/


#include "../include/KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial)    :   m_serial(serial),
                                                    _x(x), _y(y),
                                                    _next(nullptr)
{
    std::cout   <<  "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (_next)
        delete _next;
    std::cout   <<  "KreogCom " << m_serial << " shutting down" << std::endl;
}


void        KreogCom::addCom(int x, int y, int serial)
{
    KreogCom    *newKreogCom = new KreogCom(x, y, serial);

    newKreogCom->_next = _next;
    _next = newKreogCom;
}

void        KreogCom::addCom(KreogCom *com)
{
    com->_next = _next;
    _next = com;
}

int         KreogCom::getX() const
{
    return _x;
}

KreogCom    *KreogCom::getCom(void)
{
    return _next;
}


void        KreogCom::removeCom(void)
{
    if (_next) {
        KreogCom* nodeToDelete = _next;
        
        _next = _next->_next;
        nodeToDelete->_next = nullptr;
        delete nodeToDelete;
    }
}

void        KreogCom::ping(void)
{
    std::cout   <<  "KreogCom " << m_serial << " currently at "
                << _x << " " << _y << std::endl;
}

void        KreogCom::locateSquad(void)
{
    KreogCom    *current = _next;
    
    while (current)
    {
        current->ping();
        current = current->_next;
    }
    ping();
}

KreogCom    *KreogCom::getNext(void) const
{
    return _next;
}