/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:06:34 PM 2025 Paradis
** Last update Tue May 12 7:01:46 PM 2025 Paradis
*/

#include "../include/Priest.hpp"


int     main(void)
{
    Priest priest("Trichelieu", 20);
    
    priest.attack();
    priest.special();
    priest.rest();
    priest.damage(50);

    return 0;
}