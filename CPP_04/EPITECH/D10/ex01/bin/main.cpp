/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Thu May 28 6:34:41 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Orange.hpp"
#include "../include/Strawberry.hpp"
#include "../include/Almond.hpp"

int     main(void)
{
    FruitBox        box(3);
    const FruitBox& cref = box;

    box.puahFruit(new TestFruit("Cerise"));
    box.puahFruit(new TestFruit("Framboise"));
    box.puahFruit(new TestFruit("Anis"));
    std::cout << cref << std::endl;

    IFruit          *tmp = new TestFruit("Serge");

    std::cout << box.pushFruit(tmp) << std::endl;
    delete tmp;

    tmp = box.popFruit();
    delete tmp;
    std::cout << cref << std::endl;
    
    return 0;
}