/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:13:06 PM 2025 Paradis
** Last update Fri Mar 20 7:13:09 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Config.hpp"

int     main(void)
{
    DroidFactory factory(3);
    Droid **w = new Droid *[10];
    Droid *newbie;
    char c = '0';

    for (int i = 0; i < 3; ++i)
    {
        w[i] = new Droid(std::string("wreck : ") + (char) (c + i));
        *(w[i]->getBattleData()) += (i * 100);
    }

    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);

    factory >> newbie;
    std::cout << newbie << std::endl;
    factory << s1 << s2;
    std::cout << factory << std::endl;
    s3 >> factory >> newbie;
    std::cout << factory << std::endl;
    factory++ >> newbie;
    std::cout << *newbie->getBattleData() << std::endl;
    --factory >> newbie;
    std::cout << *newbie->getBattleData() << std::endl;
    
    return 0;
}