/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:25:41 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 21:01:56 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, const Weapon &weapon)  :   _name(name),
                                                            _weapon(weapon)
{}

HumanA::~HumanA(void)
{}

std::string     HumanA::getName(void) const
{
    return _name;
}

void            HumanA::setName(std::string name)
{
    _name = name;
}

const Weapon    &HumanA::getWeapon(void) const
{
    return _weapon;
}

void            HumanA::setWeapon(const Weapon &weapon)
{
    _weapon = weapon;
}

void            HumanA::attack(void) const
{
    std::cout   << _name << " attacks with their "
                << _weapon.getType() << std::endl;
}