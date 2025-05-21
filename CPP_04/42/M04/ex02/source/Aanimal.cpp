/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:24:17 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:24:31 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Aanimal.hpp"
#include <iostream>
#include <string>

// Aanimal::Aanimal(void)    :   _type("Unknown")
// {
//     std::cout   <<  "Aanimal Default Constructor created an " 
//                 << _type << " animal." << std::endl;
// }

Aanimal::Aanimal(std::string type)    :   _type(type)
{
    std::cout   <<  "Aanimal Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

Aanimal::Aanimal(const Aanimal &animal)    :   _type(animal._type)
{
    std::cout   <<  "Aanimal Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

Aanimal              &Aanimal::operator=(const Aanimal &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
        _type = animal._type;

    return *this;
}

Aanimal::~Aanimal(void)
{
    std::cout   <<  "Aanimal Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

std::string         Aanimal::getType(void) const
{
    return _type;
}

void                Aanimal::setType(std::string type)
{
    _type = type;
}

// void                Aanimal::makeSound(void) const
// {
//     std::cout   << _type << " animal sound." << std::endl;
// }