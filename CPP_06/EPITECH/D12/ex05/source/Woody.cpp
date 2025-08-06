/*
** Woody.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:38:15 PM 2025 Paradis
** Last update Thu Aug 6 8:53:10 PM 2025 Paradis
*/

#include "../include/Woody.hpp"
#include <iostream>

Woody::Woody(const std::string &name, const std::string &fileName)
    :   Toy(ToyType::WOODY, name, fileName)
{
}

Woody::~Woody(void)
{
}

bool    Woody::speak(const std::string &str)
{
    std::cout   << "WOODY: ";
    return Toy::speak(str);
}