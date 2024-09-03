/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:25:41 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 21:33:24 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)    :   _name(name),
                                        _weapon(NULL)
{}

HumanB::~HumanB(void)
{}

std::string     HumanB::getName(void) const
{
    return _name;
}

void            HumanB::setName(std::string name)
{
    _name = name;
}

const Weapon    *HumanB::getWeapon(void) const
{
    return _weapon;
}

void            HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void            HumanB::attack(void) const
{
    if (_weapon)
        std::cout   << _name << " attacks with their "
                << _weapon->getType() << std::endl;
    else
        return ;
}