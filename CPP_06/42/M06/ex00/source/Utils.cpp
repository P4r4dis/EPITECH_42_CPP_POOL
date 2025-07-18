/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:37:18 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/18 18:20:27 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <limits>
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
    double lim = std::strtod(str.c_str(), nullptr);
    if (lim < std::numeric_limits<char>::min() ||
        lim > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
    {
        std::cout << "char: ";
        if (isPrintable(std::string(1,str[0])))
            std::cout << '\'' << str << '\'' << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
}

void        Utils::printInt(const std::string &str)
{
    double lim = std::strtod(str.c_str(), nullptr);
    if (lim < std::numeric_limits<int>::min() ||
        lim > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(lim) << std::endl;
}

void        Utils::printFloat(const std::string &str)
{
    float lim = std::strtod(str.c_str(), nullptr);
    if (lim < std::numeric_limits<float>::lowest() ||
        lim > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout   << "float: " << static_cast<float>(lim);
        if (static_cast<int>(lim) == static_cast<float>(lim))
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
}

void        Utils::printDouble(const std::string &str)
{
    float lim = std::strtod(str.c_str(), nullptr);
    if (lim < std::numeric_limits<double>::lowest() ||
        lim > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
    {
        std::cout << "double: " << static_cast<double>(lim);
        if (static_cast<int>(lim) == static_cast<double>(lim))
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
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

// void        Utils::printLimits(const std::string &str)
// {
//     double lim = std::strtod(str.c_str(), nullptr);
//     if (lim < std::numeric_limits<double>::min() ||
//         lim > std::numeric_limits<double>::max())
//     {
//         std::cout   << "char: impossible" << std::endl;
//         std::cout   << "int: impossible" << std::endl;
//         std::cout   << "float: impossible" << std::endl; 
//         std::cout   << "double: impossible" << std::endl;
//         return ;
//     }

//     if (lim < std::numeric_limits<float>::min() ||
//         lim > std::numeric_limits<float>::max())
//     {
//         std::cout   << "char: impossible" << std::endl;
//         std::cout   << "int: impossible" << std::endl;
//         std::cout   << "float: impossible" << std::endl; 
//         std::cout   << "double: " << static_cast<double>(lim)<< std::endl;
//         return ;
//     }

//     if (lim < std::numeric_limits<int>::min() ||
//         lim > std::numeric_limits<int>::max())
//     {
//         std::cout   << "char: impossible" << std::endl;
//         std::cout   << "int: impossible" << std::endl;
//         std::cout   << "float: " << static_cast<float>(lim) << std::endl; 
//         std::cout   << "double: " << static_cast<double>(lim)<< std::endl;
//         return ;
//     }

//     if (lim < std::numeric_limits<char>::min() ||
//         lim > std::numeric_limits<char>::max())
//     {
//         std::cout   << "char: impossible" << std::endl;
//         std::cout   << "int: " << static_cast<int>(lim) << std::endl;
//         std::cout   << "float: " << static_cast<float>(lim) << std::endl; 
//         std::cout   << "double: " << static_cast<double>(lim)<< std::endl;
//         return ;
//     }

//     std::cout   << "char: " << static_cast<char>(lim) << std::endl;
//     std::cout   << "int: " << static_cast<int>(lim) << std::endl;
//     std::cout   << "float: " << static_cast<float>(lim) << std::endl; 
//     std::cout   << "double: " << static_cast<double>(lim)<< std::endl;
//     return ;

//     // std::cout << out_of_range << std::endl;
// }
