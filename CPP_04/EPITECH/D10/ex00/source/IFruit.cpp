/*
** IFruit.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 4:20:12 PM 2025 Paradis
** Last update Wed May 27 5:06:14 PM 2025 Paradis
*/

#include "../include/IFruit.hpp"
#include <ios>

std::ostream        &operator<<(std::ostream &os, const IFruit &fruit)
{
    os  << std::boolalpha << "[name: \"" << fruit.getName() 
        << "\", vitamins: " << fruit.getVitamins() << ", peeled: "
        << fruit.isPeeled() << "]";
    return os;
}