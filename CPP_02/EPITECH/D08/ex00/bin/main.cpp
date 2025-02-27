/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Feb 27 4:49:36 PM 2025 Paradis
** Last update Fri Feb 27 4:53:31 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Droid.hpp"

int     main(void)
{
    Droid   d;
    Droid   d1("Avenger");
    size_t  Durasel = 200;

    std::cout << d << std::endl;
    std::cout << d1 << std::endl;

    d = d1;
    d.setStatus (new std::string("Kill Kill Kill !"));
    d << Durasel;

    std::cout << d << "--" << Durasel << std::endl;

    Droid d2 = d;
    d.setId("Rex");
    std::cout << (d2 != d) << std::endl;
    
    return 0;
}