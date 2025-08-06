/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 5:28:44 PM 2025 Paradis
** Last update Thu Aug 6 6:41:54 PM 2025 Paradis
*/

#include "../include/Toy.hpp"
#include "../include/Buzz.hpp"
#include "../include/Woody.hpp"

#include <iostream>

int     main(void)
{
        Toy     toto;
        Toy     ET(Toy::ALIEN, "green", "alien.txt");//"./alien.txt");
        Woody   woody("Woody", "woody.txt");
        Buzz    buzzy("Buzz", "buzz.txt");

        toto.setName("TOTO !");
        if (toto.getType() == Toy::BASIC_TOY)
            std::cout   << "basic toy: " << toto.getName() << std::endl
                        << toto.getAscii() << std::endl;
        if (ET.getType() == Toy::ALIEN)
            std::cout   << "this alien is: " << ET.getName() << std::endl
                        << ET.getAscii() << std::endl;

        if (woody.getType() == Toy::WOODY)
            std::cout   << "this toy is: " << woody.getName() << std::endl
                        << woody.getAscii() << std::endl;

        if (buzzy.getType() == Toy::BUZZ)
            std::cout   << "this toy is: " << buzzy.getName() << std::endl
                        << buzzy.getAscii() << std::endl;
    return 0;
}