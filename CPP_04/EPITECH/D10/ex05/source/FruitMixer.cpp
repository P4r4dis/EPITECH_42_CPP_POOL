/*
** FruitMixer.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 11 5:17:21 PM 2025 Paradis
** Last update Thu Jun 11 8:35:26 PM 2025 Paradis
*/

#include "../include/FruitMixer.hpp"
#include <iostream>

FruitMixer::FruitMixer(void)    :   _blade(nullptr)
{
}

FruitMixer::~FruitMixer()
{
}

void            FruitMixer::setBlade(SteelBlade *blade)
{
    _blade = blade;
}

SteelBlade      *FruitMixer::getBlade(void) const
{
    return _blade;
}

unsigned int    FruitMixer::mixFruits(FruitBox &box)
{
    unsigned int vitamins = 0;
    
    if (_blade)
    {
        FruitBox peeled(box.getSize());
        FruitBox unpeeled(box.getSize());
        IFruit *fruit = nullptr;

        while ((fruit = box.popFruit()))
            fruit->isPeeled() ? peeled.pushFruit(fruit) : 
                                unpeeled.pushFruit(fruit);
        
        while ((fruit = peeled.popFruit()))
        {
            vitamins += fruit->getVitamins();
            delete fruit;
        }

        while ((fruit = unpeeled.popFruit()))
            box.pushFruit(fruit);
        return vitamins;
    }
    std::cout << "mixer has no blade" << std::endl;
    return vitamins;
}