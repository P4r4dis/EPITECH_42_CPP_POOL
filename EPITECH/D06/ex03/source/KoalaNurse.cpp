/*
** KoalaNurse.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:40:33 PM 2024 Paradis
** Last update Tue Jul 29 7:03:26 PM 2024 Paradis
*/
#include <iostream>

#include "../include/KoalaNurse.hpp"

KoalaNurse::KoalaNurse(std::string id)  : _id(id)
{
}

KoalaNurse::~KoalaNurse(void)
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

std::string         KoalaNurse::getId(void) const
{
    return _id;
}