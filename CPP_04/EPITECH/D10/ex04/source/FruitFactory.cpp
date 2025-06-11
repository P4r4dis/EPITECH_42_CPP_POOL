/*
** FruitFactory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 6 4:27:10 PM 2025 Paradis
** Last update Thu Jun 11 2:09:53 AM 2025 Paradis
*/

#include "../include/FruitFactory.hpp"

#include <cstddef>
#include <iostream>

FruitFactory::FruitFactory(void)    :   _nbFruit(0),
                                        _save(new IFruit*[_nbFruit + 2])
{
    for (size_t i = 0; i < _nbFruit + 2; ++i)
        _save[i] = nullptr;
}

FruitFactory::~FruitFactory()
{
    if (_save)
    {
        for (size_t i = 0; _save[i] != nullptr; ++i)
            delete _save[i];
        delete [] _save;
    }
}

void            FruitFactory::registerFruit(IFruit *fruit)
{
    if (fruit)
    {
        for (size_t i = 0; _save[i]; ++i)
        {
            if (_save[i]->getName() == fruit->getName())
            {
                delete _save[i];
                _save[i] = fruit->clone();
                delete fruit;
                return ;
            }
        }
        _save[_nbFruit] = fruit->clone();
        _save[++_nbFruit] = nullptr;
        
        IFruit **tmp = new IFruit *[_nbFruit + 2];
        for (size_t i = 0; _save[i]; ++i)
            tmp[i] = _save[i];
        tmp[_nbFruit] = nullptr;
        
        delete [] _save;
        _save = tmp;
        delete fruit;
    }
}



void            FruitFactory::unregisterFruit(const std::string &name)
{
    for (size_t i = 0; _save[i]; ++i)
    {
        if (_save[i]->getName() == name)
        {
            delete _save[i];
            _save[i] = nullptr;
            _nbFruit--;
            if (_save[i + 1])
            {
                _save[i] = _save[i + 1];
                _save[i + 1] = nullptr;;
            }
        }
    }
}

IFruit          *FruitFactory::createFruit(const std::string &name) const
{
    for (size_t i = 0; _save[i]; ++i)
    {
        if (_save[i]->getName() == name)
            return _save[i]->clone();
    }
    return nullptr;
}

void    FruitFactory::display() const
{
    for (size_t i = 0; _save[i]; ++i)
        std::cout << *_save[i] << std::endl;
}