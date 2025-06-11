/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Thu Jun 11 5:20:10 PM 2025 Paradis
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
#include "../include/IFruitMixer.hpp"
#include "../include/FruitMixer.hpp"



int     main(void)
{
    FruitBox    box(5);
    FruitMixer  yourMixer;
    IFruitMixer &mixer(yourMixer);
    SteelBlade  blade;
    IFruit      *fruit;
    
    fruit = new Orange;
    fruit->peel();
    box.pushFruit(fruit);
    box.pushFruit(new Lemon);
    box.pushFruit(new Strawberry);
    box.pushFruit(new Almond);
    std::cout << box << std::endl;

    unsigned int vitamins = mixer.mixFruits(box);

    std::cout << "result: " << vitamins << std::endl;
    std::cout << box << std::endl;

    mixer.setBlade(&blade);
    vitamins = mixer.mixFruits(box);

    std::cout << "result: " << vitamins << std::endl;
    std::cout << box << std::endl;
    
    return 0;
}