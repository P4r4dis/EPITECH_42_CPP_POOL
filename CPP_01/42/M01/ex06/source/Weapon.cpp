/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:50:07 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 19:59:48 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)    :   _type(type)
{}

Weapon::~Weapon(void)
{}

const std::string   &Weapon::getType(void) const
{
    return _type;
}

void                Weapon::setType(const std::string &type)
{
    _type = type;
}