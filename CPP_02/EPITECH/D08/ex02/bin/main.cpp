/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Mar 5 5:33:59 PM 2025 Paradis
** Last update Thu Mar 5 5:34:21 PM 2025 Paradis
*/


#include <iostream>
#include "../include/Droid.hpp"

static void testMemory()
{
    DroidMemory mem1;

    mem1 += 42;
    std::cout << mem1 << std::endl;

    DroidMemory mem2;

    mem2 << mem1;
    mem2 >> mem1;
    mem2 << mem1;
    std::cout << mem2 << std::endl;
    std::cout << mem1 << std::endl;

    DroidMemory mem3 = mem1;
    DroidMemory mem4;

    mem4 = mem1 + mem3;
}

static void testDroids ()
{
    Droid d("rudolf");
    Droid d2("gaston");
    size_t DuraSell = 40;

    d << DuraSell;
    d.setStatus(new std::string("having some reset"));
    d2.setStatus(new std::string("having some reset"));
    if (d2 != d && !(d == d2))
        std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

    d(new std::string("take a coffee"), 20);
    std::cout << d << std::endl;
    while (d(new std::string("Patrol around"), 20))
    {
        if (!d(new std::string("Shoot some ennemies"), 50))
            d(new std::string("Run Away"), 20);
        std::cout << d << std::endl;
    }
    std::cout << d << std::endl;
}

int     main(void)
{
    testMemory();
    testDroids();
    
    return 0;
}