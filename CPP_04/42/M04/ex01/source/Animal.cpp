/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:50:17 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 19:20:16 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void)    :   _type("Unknown")
{
    std::cout   <<  "Animal Default Constructor created an " 
                << _type << " animal." << std::endl;
}

Animal::Animal(std::string type)    :   _type(type)
{
    std::cout   <<  "Animal Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

Animal::Animal(const Animal &animal)    :   _type(animal._type)
{
    std::cout   <<  "Animal Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

Animal              &Animal::operator=(const Animal &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
        _type = animal._type;

    return *this;
}

Animal::~Animal(void)
{
    std::cout   <<  "Animal Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

std::string         Animal::getType(void) const
{
    return _type;
}

void                Animal::setType(std::string type)
{
    _type = type;
}

void                Animal::makeSound(void) const
{
    std::cout   << _type << " animal sound." << std::endl;
}