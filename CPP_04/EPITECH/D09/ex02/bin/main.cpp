/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:06:34 PM 2025 Paradis
** Last update Tue May 12 6:06:40 PM 2025 Paradis
*/

#include "../include/Enchanter.hpp"


int     main(void)
{
    Enchanter enchanter("Merlin", 20);
    
    enchanter.attack();
    enchanter.special();
    enchanter.rest();
    enchanter.special();
    enchanter.damage(50);

    return 0;
}