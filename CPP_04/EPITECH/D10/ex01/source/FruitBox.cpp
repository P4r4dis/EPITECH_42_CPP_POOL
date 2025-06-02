/*
** FruitBox.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:59:10 PM 2025 Paradis
** Last update Tue Jun 2 8:30:41 PM 2025 Paradis
*/

#include "../include/FruitBox.hpp"
#include <ios>

FruitBox::FruitBox(void)    :   _size(0),
                                _nbFruit(0),
                                _fruitBox(nullptr)
{
}

FruitBox::FruitBox(unsigned int sizeBox)    :   _size(sizeBox),
                                                _nbFruit(0),
                                                _fruitBox(new IFruit*[_size])
{
    for (size_t i = 0; i < _size; ++i)
        _fruitBox[i] = nullptr;
}

// FruitBox                &FruitBox::operator=(const FruitBox& fruitBox)
// {
//     if (this != &fruitBox)
//     {
//         _size = fruitBox._size;
//         _nbFruit = fruitBox._nbFruit;
//         for (size_t i = 0; i < _size; ++i)
//         {
//             if (_fruitBox[i])
//             {
//                 delete _fruitBox[i];
//                 _fruitBox[i] = nullptr;
//             }
//         }

//         for (size_t i = 0; i < _size; ++i)
//         {
//             if (fruitBox._fruitBox[i])
//                 _fruitBox[i] = fruitBox._fruitBox[i];
//         }
//     }
//     return *this;
// }

FruitBox::~FruitBox()
{
    if (_fruitBox)
    {    
        for (size_t i = 0; i < _size; ++i)
            if (_fruitBox[i])
                delete _fruitBox[i];
        delete [] _fruitBox;
    }
}

unsigned int            FruitBox::getSize(void) const
{
    return _size;
}

unsigned int            FruitBox::nbFruit(void)
{
    _nbFruit = 0;
    if (_fruitBox)
    {
        for (size_t i = 0; i < _size; ++i)
            if (_fruitBox[i])
                _nbFruit++;
        return _nbFruit;
    }
    return 0;
}

#include <sstream>
#include <iostream>
bool                    FruitBox::pushFruit(IFruit *fruit)
{
    if (_fruitBox && fruit)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_fruitBox[i] == fruit)
                return false;
            
            if (!_fruitBox[i])
            {
                _fruitBox[i] = fruit;
                return true;
            }
        }
    }
    return false;
}

IFruit                  *FruitBox::popFruit(void)
{
    if (_fruitBox)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_fruitBox[i])
            {
                IFruit *tmp = _fruitBox[i];
                _fruitBox[i] = nullptr;
                return tmp;
            }
        }
    }
    return nullptr;
}

IFruit              *FruitBox::getFruit(size_t idx) const
{
    if (idx > _size)
        return nullptr;
    return _fruitBox[idx];
}

std::ostream        &operator<<(std::ostream &os, const FruitBox &fruit)
{
    std::ostringstream tmp;

    tmp << "[";
    for (size_t i = 0; i < fruit.getSize(); ++i)
    {
        if (fruit.getFruit(i))
        {
            tmp << "[name: \"" << fruit.getFruit(i)->getName()
                << "\", vitamins: " << fruit.getFruit(i)->getVitamins()
                << ", peeled: " << std::boolalpha << fruit.getFruit(i)->isPeeled() << "]";
            if (i < fruit.getSize() - 1)
                tmp << ", ";
        }
    }

    tmp << "]";
    return os << tmp.str();
}