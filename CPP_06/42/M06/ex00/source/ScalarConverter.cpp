/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:16:38 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/17 19:05:37 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/Utils.hpp"

#include <iostream>

void        ScalarConverter::convert(const std::string &str)
{
    if (Utils::isPseudoLiteral(str))
    {
        Utils::printLiteral(str);
        return ;
    }
    else if (Utils::isChar(str))
    {
        Utils::printChar(str);
        return ;
    }
}