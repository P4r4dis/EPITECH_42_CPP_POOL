/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:16:52 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 18:26:51 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
Cure::Cure(void)    :   AMateria("cure")
{}

Cure::Cure(const std::string &type) :   AMateria(type)
{}

Cure::Cure(const Cure &cure)    :   AMateria(cure._type)
{
    if (this != &cure)
        _type = cure._type;
}

Cure             &Cure::operator=(const Cure &cure)
{
    if (this != &cure)
        _type = cure._type;
    return *this;
}

Cure::~Cure(void)
{}


Cure             *Cure::clone() const {
	return (new Cure(*this));
}

// void            Cure::use(ICharacter &target)
// {

// }

