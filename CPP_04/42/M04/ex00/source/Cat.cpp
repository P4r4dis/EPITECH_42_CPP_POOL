/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:14:09 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 19:59:50 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void)    :   Animal("Cat")
{
    std::cout   <<  "Cat Default Constructor created an " 
                << _type << " animal." << std::endl;
}

Cat::Cat(std::string type)    :   Animal(type)
{
    std::cout   <<  "Cat Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

Cat::Cat(const Cat &animal)    :   Animal(animal)
{
    std::cout   <<  "Cat Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

Cat              &Cat::operator=(const Cat &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
        _type = animal._type;

    return *this;
}

Cat::~Cat(void)
{
    std::cout   <<  "Cat Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

void            Cat::makeSound() const
{
    std::cout   << _type << " sound: MiaouMiaou." << std::endl;
}