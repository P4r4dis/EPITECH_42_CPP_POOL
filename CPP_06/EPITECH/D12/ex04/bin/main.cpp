/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex04/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 7:34:00 PM 2025 Paradis
** Last update Thu Aug 6 7:34:02 PM 2025 Paradis
*/

#include "../include/Toy.hpp"

#include <iostream>

int     main(void)
{
    Toy a(Toy::BASIC_TOY, "REX", "example.txt");

    std::cout << a;
    a << "rawr xD";
    std::cout << a;
    
    return 0;
}