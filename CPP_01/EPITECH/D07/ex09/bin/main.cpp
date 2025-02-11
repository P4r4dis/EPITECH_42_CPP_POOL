/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 7:32:31 PM 2025 Paradis
** Last update Wed Feb 11 9:27:58 PM 2025 Paradis
*/

#include "../include/Phaser.hpp"
#include <iostream>

int     main(void)
{
    Phaser p(5, Phaser::ROCKET);

    p.fire();
    p.reload();

    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
        p.fire();
    return 0;
}