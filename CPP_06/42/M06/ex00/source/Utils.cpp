/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:37:18 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/17 18:52:50 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <string>
#include <iostream>

bool         Utils::isPseudoLiteral(const std::string &str)
{
    return  str == "+inff" || str == "-inff" || str == "+inf" || str == "-inf"
            || str == "nan" || str == "nanf";
}

bool         Utils::isChar(const std::string &str)
{
   if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;

    if (str.length() == 1)
        return true;

    return false;
}

bool         Utils::isInt(const std::string &str)
{
    int index = 0;

    if (str[index] == '+' || str[index] == '-')
        ++index;

    for (size_t i = index; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool         Utils::isFloat(const std::string &str)
{
    char *end;
    std::strtof(str.c_str(), &end);
    if (*end == 'f' && *(end + 1) != '\0')
        return false;
    return true;
}

bool         Utils::isDouble(const std::string &str)
{
    char *end;
    std::strtod(str.c_str(), &end);
    if (*end != '\0')
        return false;
    return true;
}

bool         Utils::isPrintable(const std::string &str)
{
 
    return std::isprint(static_cast<unsigned char>(str.at(0)));
}

void        Utils::printChar(const std::string &str)
{
    std::cout << "char: ";
    if (isChar(std::string(1,str[0])))
    {
        if (isPrintable(std::string(1,str[0])))
            std::cout << '\'' << str << '\'' << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout   << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout   << "float: " << static_cast<float>(str[0]);
        if (static_cast<int>(str[0]) == static_cast<float>(str[0]))
            std::cout << ".0f" << std::endl;
        // else
        // {
        //     std::cout << "f" << std::endl;
        // }
        std::cout   << "double: " << static_cast<double>(str[0]);
        if (static_cast<int>(str[0]) == static_cast<double>(str[0]))
            std::cout << ".0" << std::endl;
    }
}

void            Utils::printLiteral(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        std::cout << "float: " << str << std::endl;
        std::cout   << "double: " << str.substr(0, str.length() - 1) 
                    << std::endl;
    }
    else if (str == "+inf" || str == "-inf" || str == "nan")
    {
        std::cout << "float: " << str + 'f' << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}