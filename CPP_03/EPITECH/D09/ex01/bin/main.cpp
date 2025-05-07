/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:26:02 PM 2025 Paradis
** Last update Thu May 7 5:26:14 PM 2025 Paradis
*/

#include "../include/Knight.hpp"


int     main(void)
{
    Knight knight("Arthur", 20);

    knight.attack();
    knight.special();
    knight.rest();
    knight.special();
    knight.damage(50);

    return 0;
}