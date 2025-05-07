/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 6 5:24:40 PM 2025 Paradis
** Last update Thu May 7 5:15:07 PM 2025 Paradis
*/

#include "../include/Peasant.hpp"


int     main(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.damage(100);
    peasant.damage(200);
    peasant.rest();
    return 0;
}