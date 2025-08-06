/*
** Buzz.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:37:58 PM 2025 Paradis
** Last update Thu Aug 6 8:53:23 PM 2025 Paradis
*/

#include "../include/Buzz.hpp"
#include <iostream>

Buzz::Buzz(const std::string &name, const std::string &fileName)
    :   Toy(ToyType::BUZZ, name, fileName)
{
}

Buzz::~Buzz(void)
{
}

bool    Buzz::speak(const std::string &str)
{
    std::cout   << "BUZZ: ";
    return Toy::speak(str);
}
