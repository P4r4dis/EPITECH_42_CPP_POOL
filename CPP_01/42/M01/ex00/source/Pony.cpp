/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:38:58 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 17:08:42 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Pony.hpp"

Pony::Pony(std::string name)    :   _name(name)
{
    std::cout   << "Pony name: " << _name << " is born!" << std::endl;
}

Pony::~Pony(void)
{
    std::cout   << "Pony name: " << _name << " is died!" << std::endl;
}

std::string     Pony::getName(void) const
{
    return _name;
}

void            Pony::setName(std::string name)
{
    _name = name;
}


void            ponyOnTheStack(std::string ponyName)
{
    Pony        pony(ponyName);
}

void            ponyOnTheHeap(std::string ponyName)
{
    Pony        *pony = new Pony(ponyName);
    delete pony;
}