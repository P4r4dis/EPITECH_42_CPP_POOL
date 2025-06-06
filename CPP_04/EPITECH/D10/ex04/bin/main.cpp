/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Fri Jun 5 7:19:35 PM 2025 Paradis
*/

#include <iostream>
#include "../include/FruitBox.hpp"
#include "../include/FruitUtils.hpp"
#include "../include/Orange.hpp"
#include "../include/Lemon.hpp"
#include "../include/Strawberry.hpp"
#include "../include/Almond.hpp"
#include "../include/Grapefruit.hpp"
#include "../include/BloodOrange.hpp"
#include "../include/Raspberry.hpp"
#include "../include/Coconut.hpp"
#include "../include/FruitFactory.hpp"

int     main(void)
{
    FruitFactory    factory;

    factory.registerFruit(new Raspberry);
    factory.registerFruit(new BloodOrange);
    factory.registerFruit(new Almond);
    factory.registerFruit(new Coconut);
    factory.registerFruit(new Almond);

    factory.unregisterFruit("banana");
    factory.unregisterFruit("coconut");

    IFruit          *fruit1 = factory.createFruit("almond");
    IFruit          *fruit2 = factory.createFruit("coconut");
    IFruit          *fruit3 = factory.createFruit("tomato");

    std::cout << *fruit1 << std::endl;
    std::cout << fruit2 << std::endl;
    std::cout << fruit3 << std::endl;
    
    delete fruit1;
    return 0;
}