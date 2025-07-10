/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:03:42 PM 2025 Paradis
** Last update Tue Jun 23 7:03:47 PM 2025 Paradis
*/

#include <iostream>

#include "../include/DirectoryLister.hpp"


int     main(void)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    dl.open("invalid path", true);
    if (dl.open("./test/", false) == true)
        for (std::string file = dl.get(); !file.empty(); file = dl.get())
            std::cout << file << std::endl;

    return 0;
}