/*
** KreogCom.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:53:11 PM 2025 Paradis
** Last update Thu Feb 5 4:42:41 PM 2025 Paradis
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
    std::cout   <<  "KreogCom " << m_serial << " shutting down" << std::endl;
}
