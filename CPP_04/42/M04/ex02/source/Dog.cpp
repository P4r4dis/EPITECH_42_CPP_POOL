/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:28:58 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:24:56 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void)  :   Aanimal("Dog"),
                    _brain(new Brain())
{
    std::cout   <<  "Dog Default Constructor created an " 
                << _type << " animal." << std::endl;
}

Dog::Dog(std::string type)  :   Aanimal(type),
                                _brain(new Brain())
{
    std::cout   <<  "Dog Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

Dog::Dog(const Dog &animal) :   Aanimal(animal),
                                _brain(new Brain())
{
    std::cout   <<  "Dog Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

Dog              &Dog::operator=(const Dog &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
    {
        _type = animal._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*animal._brain);
    }

    return *this;
}

Dog::~Dog(void)
{
    if (_brain)
        delete _brain;
    std::cout   <<  "Dog Destructor destroyed a " 
    << _type << " animal." << std::endl;
}

void            Dog::makeSound() const
{
    std::cout   << _type << " sound: OuafOuaf." << std::endl;
}

Brain           *Dog::getBrain(void) const
{
    return _brain;
}

void            Dog::setBrain(const Brain *brain)
{
    if (_brain)
        delete _brain;
    _brain = new Brain();
    *_brain = *brain;
}