/*
** Woody.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 7:35:10 PM 2025 Paradis
** Last update Thu Aug 6 7:35:11 PM 2025 Paradis
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

void    Woody::speak(const std::string &str)
{
    std::cout   << "WOODY: ";
    Toy::speak(str);
}