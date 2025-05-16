/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:28:58 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 18:07:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

// Dog::Dog(void)    :   Animal("Dog")
// {
//     std::cout   <<  "Dog Default Constructor created an " 
//                 << _type << " animal." << std::endl;
// }

// Dog::Dog(std::string type)    :   Animal(type)
// {
//     std::cout   <<  "Dog Custom Constructor created a " 
//                 << _type << " animal." << std::endl;
// }

// Dog::Dog(const Dog &animal)    :   Animal(animal)
// {
//     std::cout   <<  "Dog Copy Constructor created a " 
//                 << _type << " animal." << std::endl;
// }

// Dog              &Dog::operator=(const Dog &animal)
// {
//     std::cout   <<  "Assignment operator called." << std::endl;
//     if (this != &animal)
//         _type = animal._type;

//     return *this;
// }

// Dog::~Dog(void)
// {
//     std::cout   <<  "Dog Destructor destroyed a " 
//     << _type << " animal." << std::endl;
// }

// std::string         Dog::getType(void) const
// {
//     return _type;
// }

// void                Dog::setType(std::string type)
// {
//     _type = type;
// }

// void                Dog::makeSound(void)
// {
//     std::cout   << _type << " animal sound." << std::endl;
// }