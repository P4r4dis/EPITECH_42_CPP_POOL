/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:33:16 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 21:06:45 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)    :   _name(name)
{}

Zombie::~Zombie(void)
{}

// Getter
std::string     Zombie::getName(void) const
{
    return _name;
}

// Setter
void            Zombie::setName(std::string name)
{
    _name = name;
}