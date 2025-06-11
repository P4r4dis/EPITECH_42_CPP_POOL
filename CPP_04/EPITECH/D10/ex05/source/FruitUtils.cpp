/*
** FruitUtils.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 3:14:32 PM 2025 Paradis
** Last update Fri Jun 5 6:57:18 PM 2025 Paradis
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

FruitBox    **FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    if (!fruits || !*fruits || boxSize == 0)
        return nullptr;
    size_t nbFruit = 0;
    
    while (fruits[nbFruit] != nullptr)
        nbFruit++;
    
    size_t nbBox = (nbFruit + (boxSize - 1)) / boxSize;
    FruitBox **box = new FruitBox*[nbBox + 1];
    
    for (size_t i = 0; i < nbBox; ++i)
    {
        box[i] = new FruitBox(boxSize);
        for (size_t j = 0; j < boxSize && (i * boxSize + j) < nbFruit; ++j)
        {
            box[i]->pushFruit(fruits[i * boxSize + j]);
            fruits[i * boxSize + j] = nullptr;
        }
    }
    box[nbBox] = nullptr;
    return box;
}

IFruit      **FruitUtils::unpack(FruitBox **fruitBoxes)
{
    size_t nbFruit = 0;

    if (!fruitBoxes || !*fruitBoxes)
        return nullptr;
    
    for (size_t i = 0; fruitBoxes[i] != nullptr; ++i)
        nbFruit += fruitBoxes[i]->nbFruit();
    
    IFruit **fruit = new IFruit*[nbFruit + 1];
    size_t idx = 0;
    
    for (size_t i = 0; fruitBoxes[i] != nullptr; ++i)
    {
        IFruit *tmp = nullptr;
        while ((tmp = fruitBoxes[i]->popFruit()) != nullptr)
            fruit[idx++] = tmp;
    }
    fruit[idx] = nullptr;
    
    return fruit;
}