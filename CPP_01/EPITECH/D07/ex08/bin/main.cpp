/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:48:44 PM 2025 Paradis
** Last update Thu Feb 5 3:48:49 PM 2025 Paradis
*/

#include "../include/KreogCom.hpp"

int main(void)
{
    KreogCom k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);

    k.locateSquad();

    k.removeCom();
    k.removeCom();

    return 0;
}