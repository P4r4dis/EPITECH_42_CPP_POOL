/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:16:38 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:37:18 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/Utils.hpp"

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
        Utils::convertToChar(str);
        return ;
    }
    
    Utils::printChar(str);
    Utils::printInt(str);
    Utils::printFloat(str);
    Utils::printDouble(str);

    return ;
}