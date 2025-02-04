/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:06:48 PM 2025 Paradis
** Last update Wed Feb 4 1:11:47 PM 2025 Paradis
*/

#include "../include/Skat.hpp"
#include <iostream>

int main(void)
{
    Skat s("Junior", 5);
    
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks(); 

    return 0;
}