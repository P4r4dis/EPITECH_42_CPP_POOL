/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 11 5:51:44 PM 2025 Paradis
** Last update Wed Mar 18 4:44:33 PM 2025 Paradis
*/

#include <iostream>
#include "../include/Supply.hpp"

int     main(void)
{
    Droid ** w = new Droid*[10];
    char c = '0';

    for (int i = 0; i < 3; ++i)
        w[i] = new Droid(std::string("wreck: ") + (char) (c + i));
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    std::cout << s3 << std::endl;
    
    size_t s = s2;
    std::cout << s << std::endl;
    std::cout << *(*(--s3)) << std::endl;
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << !s3 << std::endl;
    
    return 0;
}