/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 3:40:45 PM 2025 Paradis
** Last update Thu May 28 6:23:19 PM 2025 Paradis
*/


#include <iostream>
#include "../include/Orange.hpp"
#include "../include/Strawberry.hpp"
#include "../include/Almond.hpp"

int     main(void)
{
    Orange          o;
    Strawberry      s;
    const Almond    a;
    IFruit&         f = o;

    std::cout   << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
    std::cout   << s << std::endl;
    std::cout   << a << std::endl;

    o.peel();
    std::cout   << f << std::endl;

    return 0;
}