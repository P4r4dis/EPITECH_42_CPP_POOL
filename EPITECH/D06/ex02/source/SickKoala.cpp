/*
** SickKoala.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 26 8:01:29 PM 2024 Paradis
** Last update Sat Jul 26 9:18:34 PM 2024 Paradis
*/


#include <iostream>

#include "../include/SickKoala.hpp"

SickKoala::SickKoala(std::string name)  :   _name(name)
{}

SickKoala::~SickKoala(void)
{
    std::cout   << "Mr." << _name << ": Kreooogg!! I'm cuuuured!"
                << std::endl;
}

std::string         SickKoala::getName(void) const
{
    return _name;
}