/*
** Buzz.cpp for ' in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 6:56:28 PM 2025 Paradis
** Last update Thu Aug 6 7:02:49 PM 2025 Paradis
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

void    Buzz::speak(const std::string &str)
{
    std::cout   << "BUZZ: ";
    Toy::speak(str);
}
