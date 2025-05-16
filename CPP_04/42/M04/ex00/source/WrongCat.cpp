/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:41:32 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 18:43:43 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)    :   WrongAnimal("WrongCat")
{
    std::cout   <<  "WrongCat Default Constructor created an " 
                << _type << " animal." << std::endl;
}

WrongCat::WrongCat(std::string type)    :   WrongAnimal(type)
{
    std::cout   <<  "WrongCat Custom Constructor created a " 
                << _type << " animal." << std::endl;
}

WrongCat::WrongCat(const WrongCat &animal)    :   WrongAnimal(animal)
{
    std::cout   <<  "WrongCat Copy Constructor created a " 
                << _type << " animal." << std::endl;
}

WrongCat              &WrongCat::operator=(const WrongCat &animal)
{
    std::cout   <<  "Assignment operator called." << std::endl;
    if (this != &animal)
        _type = animal._type;

    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout   <<  "WrongCat Destructor destroyed a " 
    << _type << " animal." << std::endl;
}