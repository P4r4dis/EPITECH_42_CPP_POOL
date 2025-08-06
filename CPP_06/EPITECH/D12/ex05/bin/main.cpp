/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:31:58 PM 2025 Paradis
** Last update Thu Aug 6 8:38:42 PM 2025 Paradis
*/

#include "../include/Toy.hpp"
#include "../include/Woody.hpp"

#include <iostream>

int     main(void)
{
    Woody   w("wood");
    
    if (w.setAscii("file_who_does_not_exist.txt") == false)
    {
        auto e = w.getLastError();
        if (e.type == Toy::Error::PICTURE)
            std::cout   << "Error in " << e.where() << ": " << e.what()
                        << std::endl;
    }

    if (w.speak_es("Woody does not have spanish mode") == false) 
    {
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK) 
            std::cout   << "Error in " << e.where() << ": " << e.what()
                        << std::endl;
    }

    if (w.speak_es("Woody does not have spanish mode") == false) 
    {
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK) 
            std::cout   << "Error in " << e.where() << ": " << e.what()
                        << std::endl;
    }
    
    return 0;
}