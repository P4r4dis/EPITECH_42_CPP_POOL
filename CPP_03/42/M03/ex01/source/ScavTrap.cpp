/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:41:02 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/29 18:39:03 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_name = "ScavTrap";
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << _name << " Default CTOR called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)     :   ClapTrap(name)
{
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << _name << " Custom CTOR called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)    :   ClapTrap(scavTrap)
{
    // if (this != &scavTrap)
    //     *this = scavTrap;
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