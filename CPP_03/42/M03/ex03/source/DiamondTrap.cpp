/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:49:20 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/06 17:06:42 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void)  :   _name("DiamondTrap")
{
    _hit = 100;
    _energy = 50;
    _attack = 30;
    ClapTrap::_name = _name + "_clap_name";

    std::cout   << "DiamondTrap " << _name << " Default CTOR called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)  :   _name(name)
{
    _hit = 100;
    _energy = 50;
    _attack = 30;
    ClapTrap::_name = name + "_clap_name";
    std::cout   << "DiamondTrap " << _name << " Custom CTOR called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :  ClapTrap(diamondTrap),
                                                            FragTrap(diamondTrap),
                                                            ScavTrap(diamondTrap)
                                                            
{
    if (this != &diamondTrap)
    {
        _name = diamondTrap._name;
        ClapTrap::_name = diamondTrap._name + "_clap_name";
        _hit = diamondTrap._hit;
        _energy = diamondTrap._energy;
        _attack = diamondTrap._attack;
    }
    std::cout   << "DiamondTrap " << _name << " Copy CTOR called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout   << "DiamondTrap " << _name << " DTOR called" << std::endl;
}

DiamondTrap             &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    if (this != &diamondTrap)
    {
        _name = diamondTrap._name;
        ClapTrap::_name = diamondTrap._name + "_clap_name";
        _hit = diamondTrap._hit;
        _energy = diamondTrap._energy;
        _attack = diamondTrap._attack;
    }

    return *this;
}

std::string             DiamondTrap::getName(void) const
{
    return _name;
}

void                    DiamondTrap::setName(std::string name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
}

void                    DiamondTrap::whoAmI(void)
{
    std::cout   << "DiamonTrap name: " << _name << " and ClapTrap name: " << ClapTrap::_name << std::endl;
}