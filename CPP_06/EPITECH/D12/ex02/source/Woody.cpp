/*
** Woody.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 6:21:07 PM 2025 Paradis
** Last update Thu Aug 6 6:21:37 PM 2025 Paradis
*/

#include "../include/Woody.hpp"

Woody::Woody(const std::string &name, const std::string &fileName)
    :   Toy(ToyType::WOODY, name, fileName)
{
}

Woody::~Woody(void)
{
}
