/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:22:55 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 20:38:47 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria(void)    :   _type("Unknown")
{}

AMateria::AMateria(const std::string &type) :   _type(type)
{}

AMateria::AMateria(const AMateria &amateria)    :   _type(amateria._type)
{}

AMateria            &AMateria::operator=(const AMateria &amateria)
{
    if (this != &amateria)
        _type = amateria._type;

    return *this;
}

AMateria::~AMateria(void)
{}

std::string const   &AMateria::getType(void) const
{
    return _type;
}