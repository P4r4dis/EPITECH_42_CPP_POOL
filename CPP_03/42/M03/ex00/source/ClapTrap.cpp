/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:45:09 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/18 19:36:01 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string &name) :   _name(name),
                                                _hit(10),
                                                _energy(10),
                                                _attack(0)
{
    std::cout << "CTOR called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)    :   _name(claptrap._name),
                                                    _hit(claptrap._hit),
                                                    _energy(claptrap._energy),
                                                    _attack(claptrap._attack)
{
    std::cout << "Copy CTOR called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "DTOR called" << std::endl;
}

ClapTrap                &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this != &clapTrap)
    {
        _name = clapTrap._name;
        _hit = clapTrap._hit;
        _energy = clapTrap._energy;
        _attack = clapTrap._attack;
    }

    return *this;
}
const std::string       &ClapTrap::getName(void) const
{
    return _name;
}

void                    ClapTrap::setName(const std::string &name)
{
    _name = name;
}

size_t                  ClapTrap::getHit(void) const
{
    return _hit;
}

void                    ClapTrap::setHit(size_t hit)
{
    _hit = hit;
}

size_t                  ClapTrap::getEnergy(void) const
{
    return _energy;
}

void                    ClapTrap::setEnergy(size_t energy)
{
    _energy = energy;
}

size_t                  ClapTrap::getAttack(void) const
{
    return _attack;
}

void                    ClapTrap::setAttack(size_t attack)
{
    _attack = attack;
}

void                    ClapTrap::attack(const std::string &target)
{
    if (_hit > 0 && _energy > 0)
    {
        _energy--;
        std::cout   << "ClapTrap " << _name << " attacks " 
                    << target << ", causing " << _attack 
                    << " points of damage!" << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap " << _name << " can't attack " 
                    << target << ", causing 0 points of damage!"
                    << std::endl
                    << "ClapTrap " << _name << " has no hit or energy points"
                    << std::endl;
    }
}