/*
** Grapefruit.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:11:49 PM 2025 Paradis
** Last update Wed Jun 3 2:12:29 PM 2025 Paradis
*/



#include "../include/Grapefruit.hpp"

Grapefruit::Grapefruit(void)  :   ACitrus("grapefruit", 5)
{
}

Grapefruit::Grapefruit(const std::string& name, unsigned int vitamins, bool peeled)
    :   ACitrus(name, vitamins, peeled)
{
}

Grapefruit               &Grapefruit::operator=(const Grapefruit& grapefruit)
{
    if (this != &grapefruit)
    {
        _vitamins = grapefruit._vitamins;
        _name = grapefruit._name;
        _peeled = grapefruit._peeled;
    }
    return *this;
}

Grapefruit::~Grapefruit()
{
}
