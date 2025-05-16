/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:40:31 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 20:07:12 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void)    :   _type("Unknown")
{
    std::cout   <<  "WrongAnimal Default Constructor created an " 
                << _type << " animal." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)    :   _type(type)
{
    std::cout   <<  "WrongAnimal Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)    :   _type(animal._type)
{
    std::cout   <<  "WrongAnimal Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

WrongAnimal              &WrongAnimal::operator=(const WrongAnimal &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
        _type = animal._type;

    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout   <<  "WrongAnimal Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

std::string         WrongAnimal::getType(void) const
{
    return _type;
}

void                WrongAnimal::setType(std::string type)
{
    _type = type;
}

void                WrongAnimal::makeSound(void) const
{
    std::cout   << _type << " animal sound." << std::endl;
}