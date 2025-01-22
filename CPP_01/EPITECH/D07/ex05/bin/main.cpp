/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex05/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jan 21 6:31:11 PM 2025 Paradis
** Last update Thu Jan 22 2:38:44 AM 2025 Paradis
*/

#include "../include/Exam.hpp"

bool Exam::cheat = false;

int main(void)
{
    Exam    e = Exam(&Exam::cheat);
    e.kobayashiMaru = &Exam::start;

    (e.*e.kobayashiMaru)(3);
    Exam::cheat = true;
    if (e.isCheating())
        (e.*e.kobayashiMaru)(4);
}