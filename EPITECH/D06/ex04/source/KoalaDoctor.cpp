/*
** KoalaDoctor.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 30 6:03:42 PM 2024 Paradis
** Last update Wed Jul 30 6:09:29 PM 2024 Paradis
*/
#include <iostream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)  :   _name(name)
{
    std::cout   << "Dr." << _name << ": I'm Dr." 
                << _name << "! How do you kreog?"
                << std::endl;
}

KoalaDoctor::~KoalaDoctor(void)
{
}

std::string         KoalaDoctor::getName(void) const
{
    return _name;
}