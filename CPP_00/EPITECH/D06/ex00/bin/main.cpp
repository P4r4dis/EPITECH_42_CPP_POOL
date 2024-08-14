/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 19 6:27:04 PM 2024 Paradis
** Last update Fri Jul 25 5:57:56 PM 2024 Paradis
*/

#include "../include/MyCat.hpp"

int main(int ac, char **av)
{
    MyCat   myCat;
    if (ac < 2)
        myCat.usage();
    else
        for (int i = 1; i < ac; ++i)
            myCat.myCat(av[i]);
    return 0;
}