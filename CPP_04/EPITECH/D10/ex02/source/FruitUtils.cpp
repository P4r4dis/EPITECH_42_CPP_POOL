/*
** FruitUtils.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 3:14:32 PM 2025 Paradis
** Last update Wed Jun 3 6:58:07 PM 2025 Paradis
*/

#include "../include/FruitUtils.hpp"
#include "../include/Lemon.hpp"
#include "../include/ABerry.hpp"

FruitUtils::FruitUtils(void)
{
}

FruitUtils::~FruitUtils(void)
{
}

void        FruitUtils::sort(FruitBox &unsorted,
                            FruitBox &lemon,
                            FruitBox &citrus,
                            FruitBox &berry)
{
    FruitBox    tmp(unsorted.nbFruit());
    IFruit      *fruit = nullptr;
    
    for (size_t i = 0; (fruit = unsorted.popFruit()) != nullptr; ++i)
    {
        bool pushed = false;
        if (dynamic_cast<Lemon *>(fruit))
            pushed = lemon.pushFruit(fruit);
        else if (dynamic_cast<ACitrus *>(fruit))
            pushed = citrus.pushFruit(fruit);
        else if (dynamic_cast<ABerry *>(fruit))
            pushed = berry.pushFruit(fruit);

        if (!pushed)
            tmp.pushFruit(fruit);
    }

    while ((fruit = tmp.popFruit()))
        unsorted.pushFruit(fruit);
}
