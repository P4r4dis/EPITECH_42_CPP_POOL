/*
** Toy.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Aug 5 6:40:04 PM 2025 Paradis
** Last update Wed Aug 5 7:04:50 PM 2025 Paradis
*/

#include "../include/Toy.hpp"

Toy::Toy(void)  :   _type(BASIC_TOY),
                    _name("toy"),
                    _fileName(""),
                    _picture(_fileName)
{
}

Toy::~Toy()
{
}

Toy::ToyType     Toy::getType(void) const
{
    return _type;
}

std::string     Toy::getName(void) const
{
    return _name;
}