/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:06:34 PM 2025 Paradis
** Last update Thu May 14 4:37:23 PM 2025 Paradis
*/

#include "../include/ICharacter.hpp"
#include "../include/Peasant.hpp"
#include "../include/IPotion.hpp"

#include <iostream>

int     main(void)
{
    ICharacter      *peasant = new Peasant("Gildas", 42);
    PoisonPotion    poison_potion;
    HealthPotion    health_potion;
    IPotion         &potion = health_potion;

    std::cout << peasant->getName() << ": " << peasant->getHp() << " HP, "
    << peasant->getPower() << " PP." << std::endl;

    peasant->drink(poison_potion);

    std::cout << peasant->getName() << ": " << peasant->getHp() << " HP, "
    << peasant->getPower() << " PP." << std::endl;

    peasant->drink(potion) ;

    std::cout << peasant->getName() << ": " << peasant->getHp() << " HP, "
    << peasant->getPower() << " PP." << std::endl;

    delete peasant;

    return 0;
}