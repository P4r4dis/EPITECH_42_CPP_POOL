/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 6:52:56 PM 2025 Paradis
** Last update Thu Aug 6 6:52:58 PM 2025 Paradis
*/

#include "../include/Toy.hpp"
#include "../include/Buzz.hpp"
#include "../include/Woody.hpp"

#include <memory>

int     main(void)
{
    std::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "alien.txt"));

    b->speak("To the code, and beyond !!!!!!!!");
    w->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");
    
    return 0;
}