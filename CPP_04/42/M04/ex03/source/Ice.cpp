/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:16:52 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 20:30:01 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>
Ice::Ice(void)  :   AMateria("ice")
{}

Ice::Ice(const std::string &type)   :   AMateria(type)
{}

Ice::Ice(const Ice &ice)    :   AMateria(ice._type)
{
    if (this != &ice)
        _type = ice._type;
}

Ice             &Ice::operator=(const Ice &ice)
{
    if (this != &ice)
        _type = ice._type;
    return *this;
}

Ice::~Ice(void)
{}


Ice             *Ice::clone() const {
	return (new Ice(*this));
}

void            Ice::use(ICharacter &target)
{
    std::cout   << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

