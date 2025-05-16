/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:06:34 PM 2025 Paradis
** Last update Wed May 13 6:50:30 PM 2025 Paradis
*/

#include "../include/ICharacter.hpp"
#include "../include/Peasant.hpp"
#include "../include/Knight.hpp"
#include "../include/Enchanter.hpp"
#include "../include/Priest.hpp"
#include "../include/Paladin.hpp"
#include <iostream>

int     main(void)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    ICharacter *knight = new Knight("Arthur", 20);
    ICharacter *enchanter = new Enchanter("Merlin", 20);
    ICharacter *priest = new Priest("Trichelieu", 20);
    ICharacter *paladin = new Paladin("Uther", 99);

    peasant->attack();
    knight->special();
    enchanter->rest();
    priest->damage(21);
    
    std::cout   << paladin->getName() << ": "
                << paladin->getHp() << " health points, "
                << paladin->getPower() << " power points."
                << std::endl;

    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;

    return 0;
}