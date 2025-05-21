/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:14:09 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:24:47 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void)  :   Aanimal("Cat"),
                    _brain(new Brain())
{
    std::cout   <<  "Cat Default Constructor created an " 
                << _type << " animal." << std::endl;
}

Cat::Cat(std::string type)  :   Aanimal(type),
                                _brain(new Brain())
{
    std::cout   <<  "Cat Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

Cat::Cat(const Cat &animal) :   Aanimal(animal),
                                _brain(new Brain())
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
    if (_brain)
        delete _brain;
    std::cout   <<  "Cat Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

void            Cat::makeSound() const
{
    std::cout   << _type << " sound: MiaouMiaou." << std::endl;
}

Brain           *Cat::getBrain(void) const
{
    return _brain;
}

void            Cat::setBrain(const Brain *brain)
{
    if (_brain)
        delete _brain;
    _brain = new Brain();
    *_brain = *brain;
}