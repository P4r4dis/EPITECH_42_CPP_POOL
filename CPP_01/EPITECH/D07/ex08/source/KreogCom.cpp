/*
** KreogCom.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:53:11 PM 2025 Paradis
** Last update Thu Feb 5 9:50:46 PM 2025 Paradis
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