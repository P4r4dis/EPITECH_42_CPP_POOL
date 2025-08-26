/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 4:53:40 PM 2025 Paradis
** Last update Fri Aug 7 4:55:09 PM 2025 Paradis
*/



#include "../include/Buzz.hpp"
#include "../include/Woody.hpp"
#include "../include/ToyStory.hpp"

int     main(void)
{
    Buzz    b("buzzi");
    Woody   w("wood");

    ToyStory::tellMeAStory("superStory.txt", b, &Toy::speak_es, w, &Toy::speak);
    
    return 0;
}