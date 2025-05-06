/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:41:02 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/05 20:29:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void)    :   _guardGate(false)
{
    this->_name = "ScavTrap";
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << _name << " Default CTOR called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)     :   
                                                    _guardGate(false)
{
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << _name << " Custom CTOR called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)    :   ClapTrap(scavTrap),
                                                    _guardGate(false)
{
    std::cout << "ScavTrap " << _name << " Copy CTOR called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << " DTOR called" << std::endl;
}

ScavTrap        &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    if (this != &scavTrap)
        ClapTrap::operator=(scavTrap);

    return *this;
}

void            ScavTrap::attack(const std::string &target)
{
    if (_hit > 0 && _energy > 0)
    {
        _energy--;
        std::cout   << "ScavTrap " << _name << " attacks " 
                    << target << ", causing " << _attack 
                    << " points of damage!" << std::endl;
    }
    else
    {
        std::cout   << "ScavTrap " << _name << " can't attack " 
                    << target << ", causing 0 points of damage!"
                    << std::endl
                    << "ScavTrap " << _name << " has no hit or energy points"
                    << std::endl;
    }
}

void            ScavTrap::guardGate(void)
{
    if (_guardGate == false)
    {
        _guardGate = true;
        std::cout   << "ScavTrap " << _name << " activates the guard mode!" << std::endl;
    }
    else
    {
        _guardGate = false;
        std::cout   << "ScavTrap " << _name << " desactivates the guard mode!" << std::endl;
    }
}

bool            ScavTrap::getGuardGate(void) const
{
    return _guardGate;
}