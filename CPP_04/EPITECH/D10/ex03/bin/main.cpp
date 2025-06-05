/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Fri Jun 5 6:54:27 PM 2025 Paradis
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

int     main(void)
{
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;

        FruitBox **tmp = FruitUtils::pack(fruits, 6);

        std::cout << "Fruits are packed in the fruitbox:" << std::endl;
        for (size_t i = 0; tmp[i] != nullptr; ++i)
            std::cout << *tmp[i] << std::endl;
        
        std::cout << "Fruits are unpacked in the new array of Fruits:" << std::endl;
        IFruit **unpackedFruits = FruitUtils::unpack(tmp);
        for (size_t i = 0; unpackedFruits[i] != nullptr; ++i)
            std::cout << *unpackedFruits[i] << std::endl;

        std::cout << "Now the old array of fruits are empty!" << std::endl;

        for (size_t i = 0; tmp[i] != nullptr; ++i)
            delete tmp[i];
        delete [] tmp;

        for (size_t i = 0; unpackedFruits[i] != nullptr; ++i)
                delete unpackedFruits[i];
        delete [] unpackedFruits;
    
    return 0;
}