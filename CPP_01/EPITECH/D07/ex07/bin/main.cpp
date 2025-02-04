/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 1:25:38 PM 2025 Paradis
** Last update Wed Feb 4 9:09:57 PM 2025 Paradis
*/

#include <iostream>
#include "../include/KoalaBot.hpp"

int main(void)
{
    KoalaBot kb;

    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    return 0;
}