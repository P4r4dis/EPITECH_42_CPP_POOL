/*
** Federation.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:17:29 PM 2024 Paradis
** Last update Sat Sep 20 9:17:35 PM 2024 Paradis
*/

#include "../include/Federation.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(
    int length, int width, std::string name, short maxWarp)
    :   _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
    std::cout   << "The ship USS " << _name << " has been finished."
                << std::endl << "It is " << _length
                << " m in length and " << _width << " m in width."
                << std::endl << "It can go to Warp " << _maxWarp << "!"
                << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}
