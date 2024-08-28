/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:38:58 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/28 15:42:23 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Pony.hpp"

Pony::Pony(std::string name)    :   _name(name)
{}

Pony::~Pony(void)
{}

std::string     Pony::getName(void) const
{
    return _name;

}

void            Pony::setName(std::string name)
{
    _name = name;
}