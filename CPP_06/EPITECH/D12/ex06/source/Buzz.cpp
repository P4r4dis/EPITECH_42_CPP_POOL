/*
** Buzz.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 4:55:52 PM 2025 Paradis
** Last update Fri Aug 7 4:55:54 PM 2025 Paradis
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

bool    Buzz::speak_es(const std::string &str)
{
    std::cout   << "BUZZ: " << Toy::getName() << " senorita \"" 
                << str << "\" senorita" << std::endl;
    return true;
}
