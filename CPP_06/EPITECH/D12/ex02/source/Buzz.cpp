/*
** Buzz.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 5:43:15 PM 2025 Paradis
** Last update Thu Aug 6 5:47:48 PM 2025 Paradis
*/

#include "../include/Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &fileName)
    :   Toy(ToyType::BUZZ, name, fileName)
{
}

Buzz::~Buzz(void)
{
}
