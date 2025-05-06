/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:37:51 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/30 19:51:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_name = "FragTrap";
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap " << _name << " Default CTOR called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) :   ClapTrap(name)
{
    this->_name = name;
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap " << _name << " Custom CTOR called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)    :   ClapTrap(fragTrap)
{
    std::cout << "FragTrap " << _name << " Copy CTOR called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << " DTOR called" << std::endl;
}

FragTrap        &FragTrap::operator=(const FragTrap &fragTrap)
{
    if (this != &fragTrap)
        ClapTrap::operator=(fragTrap);

    return *this;
}

void            FragTrap::highFivesGuy(void)
{
    std::cout   <<  _name << " does High Fives Guys!" << std::endl;
}
