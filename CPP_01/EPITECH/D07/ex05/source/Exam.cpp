/*
** Exam.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jan 21 6:29:26 PM 2025 Paradis
** Last update Thu Jan 22 2:37:55 AM 2025 Paradis
*/

#include "../include/Exam.hpp"
#include <iostream>

Exam::Exam(bool *ptr)
{
    *ptr = cheat;
}

Exam::~Exam()
{
}

void    Exam::start(int nb_Klingon)
{
    std::cout   << "[The exam is starting]" << std::endl;
    std::cout   << nb_Klingon << " Klingon vessels appeared out of nowhere."
                << std::endl;
    std::cout   << "they are fully armed and shielded" << std::endl;
    if (cheat)
    {
        std::cout   << "What the... someone changed the parameters of the exam !"
                    << std::endl;
    }
    else
        std::cout   << "This exam is hard... you lost again." << std::endl;
}

bool    Exam::isCheating(void) const
{
    return cheat;
}