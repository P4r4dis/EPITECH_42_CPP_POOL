/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:03:50 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 17:39:38 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "../include/Brain.hpp"

Brain::Brain(void)
{}

Brain::~Brain(void)
{}

std::string     Brain::identify(void)
{
    std::ostringstream oss;
    std::string str;

    oss << this;
    str = oss.str();

    for (std::size_t i = 2; i < str.length(); ++i)
        str[i] = std::toupper(str[i]);

    return str;
}