/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:07:36 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 18:23:23 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include <iostream>

Character::Character(void)  :   ICharacter(),
                                _name("Unknown")
{
    for (int i = 0; i < INVENTORY_SIZE; ++i)
        _inventory[i] = nullptr;
}

Character::Character(const std::string &name)   :   ICharacter(),
                                                    _name(name)
{
    for (int i = 0; i < INVENTORY_SIZE; ++i)
        _inventory[i] = nullptr;
}

Character::Character(const Character &character)    :   ICharacter(),
                                                        _name(character._name)
{
    for (int i = 0; i < INVENTORY_SIZE; ++i)
    {
        if (character._inventory[i])
            _inventory[i] = character._inventory[i]->clone();
        else
            _inventory[i] = nullptr;
    }
}

Character               &Character::operator=(const Character &character)
{
    if (this != &character)
    {
        _name = character._name;
        for (int i = 0; i < INVENTORY_SIZE; ++i)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = nullptr;
            }
        }

        for (int i = 0; i < INVENTORY_SIZE; ++i)
        {
            if (character._inventory[i])
                _inventory[i] = character._inventory[i]->clone();
            else
                _inventory[i] = nullptr;
        }
    }
    return *this;
}

Character::~Character(void)
{
    for (int i = 0; i < INVENTORY_SIZE; ++i)
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
}

const std::string       &Character::getName(void) const
{
    return _name;
}

void                    Character::equip(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < INVENTORY_SIZE; ++i)
        {
            if (!_inventory[i])
            {
                _inventory[i] = m;
                std::cout   << "Emplacement " << i << " is equiped." << std::endl;
                return ;
            }   
        }

        for (int i = 0; i < INVENTORY_SIZE; ++i)
            if (_inventory[i] && i == INVENTORY_SIZE - 1)
                std::cout   << "Inventory is full." << std::endl;
    }
    else
        std::cout   << "Materia doesn't exist." << std::endl;
}

void                    Character::unequip(int idx)
{
    if (idx >= 0 && idx < INVENTORY_SIZE)
    {
        if (_inventory[idx])
        {
            std::cout   << "Emplacement " << idx << " is unequipped." << std::endl;
            _inventory[idx] = nullptr;
        }
        else
            std::cout   << "Emplacement " << idx << " is empty." << std::endl;
    }
    else
        std::cout   << "No slot at the index." << std::endl;
}

void                    Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < INVENTORY_SIZE)
    {
        if (_inventory[idx])
        {
            _inventory[idx]->use(target);
            std::cout   << "Materia at the index: " 
                        << idx << " is used." << std::endl;
        }
        else
            std::cout   << "Emplacement " << idx << " is empty." << std::endl;
    }
    else
        std::cout   << "Emplacement " << idx << " doesn't exist." << std::endl;
}