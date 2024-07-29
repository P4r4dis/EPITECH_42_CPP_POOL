/*
** SickKoala.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 26 8:01:29 PM 2024 Paradis
** Last update Tue Jul 29 4:13:25 PM 2024 Paradis
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

void                SickKoala::poke(void)
{
    std::cout << "Mr.koala: Gooeeeeerrk!!" << std::endl;
}

bool                SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars")
    {
        std::cout   << "Mr." << _name << ": Mars, and it kreogs!"
                    << std::endl;
        return true;
    }
    else if (drug == "Kinder")
    {
        std::cout   << "Mr." << _name << ": There is a toy inside!"
                    << std::endl;
        return true;       
    }
    else
    {
        std::cout   << "Mr." << _name << ": Goerkreog!"
                    << std::endl;
        return false;  
    }
}