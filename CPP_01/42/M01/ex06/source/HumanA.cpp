/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:25:41 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 20:46:32 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"
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