/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Mar 3 4:51:59 PM 2025 Paradis
** Last update Tue Mar 3 4:54:47 PM 2025 Paradis
*/


#include <iostream>
#include "../include/Droid.hpp"

int     main(void)
{
    DroidMemory mem1;

    mem1 += 42;
    
    DroidMemory mem2 = mem1;

    std::cout << mem1 << std::endl;

    DroidMemory mem3;

    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;

    std::cout << mem3 << std::endl;
    std::cout << mem1 << std::endl;
    
    return 0;
}