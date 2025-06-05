/*
** Coconut.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:44:34 PM 2025 Paradis
** Last update Wed Jun 3 2:45:08 PM 2025 Paradis
*/



#include "../include/Coconut.hpp"

Coconut::Coconut(void)  :   ANut("coconut", 4)
{
}

Coconut::Coconut(const std::string& name, unsigned int vitamins, bool peeled)
    :   ANut(name, vitamins, peeled)
{
}

Coconut               &Coconut::operator=(const Coconut& coconut)
{
    if (this != &coconut)
    {
        _vitamins = coconut._vitamins;
        _name = coconut._name;
        _peeled = coconut._peeled;
    }
    return *this;
}

Coconut::~Coconut()
{
}
