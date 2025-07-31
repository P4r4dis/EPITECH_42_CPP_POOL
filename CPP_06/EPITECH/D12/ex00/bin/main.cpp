/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 31 5:32:56 PM 2025 Paradis
** Last update Fri Jul 31 6:20:04 PM 2025 Paradis
*/

#include <iostream>

int     main(void)
{
    Toy     toto;
    Toy     ET(Toy::ALIEN, "green", "./alien.txt");

    toto.setName("TOTO!");
    if (toto.getType() == Toy::BASIC_TOY)
        std::cout   << "basic toy: " << toto.getName() << std::endl
                    << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout   << "this alien is : " << ET.getName() << std::endl
                    << ET.getAscii() << std::endl;
    return 0;
}