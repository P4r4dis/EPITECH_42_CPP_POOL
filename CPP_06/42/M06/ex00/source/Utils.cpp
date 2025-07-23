/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:37:18 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:36:27 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include <cstdlib>
#include <limits>
#include <cfloat>
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
    
    std::strtod(str.c_str(), &end);

    if ((*end == 'f' && *(end + 1) != '\0'))
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
    char    *end;
    double  lim = std::strtod(str.c_str(), &end);

    std::cout << "char: ";
    if ((lim < std::numeric_limits<char>::min()
        || lim > std::numeric_limits<char>::max())
        || (str.length() > 3 && *end != 'f' && lim == 0))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    if (str.length() == 3 && str[0] == '\'' && str[str.length() - 1] == '\'' &&
        isPrintable(std::string(1, str[1])))
        std::cout << '\'' << static_cast<char>(str[1]) << '\'' << std::endl;
    else if (str.length() == 1 && str[0] != 0
            && isPrintable(std::string(1, str[0])))
    {
        if ((str[0] >= '0' || str[0] <= '9') && (str[0] < 97 || str[0] > 122))
        {
            std::cout << "Non displayable" << std::endl;
            return ;
        }
        std::cout << '\'' << static_cast<char>(str[0]) << '\'' << std::endl;
    }
    else if (isPrintable(std::string(1, lim)))
        std::cout << '\'' << static_cast<char>(lim) << '\'' << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void        Utils::printInt(const std::string &str)
{
    char *end;
    double lim = std::strtod(str.c_str(), &end);

    if ((lim < std::numeric_limits<int>::min() ||
        lim > std::numeric_limits<int>::max()) || (end == str))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(lim) << std::endl;
}

void        Utils::printFloat(const std::string &str)
{
    char *end;
    float lim = std::strtod(str.c_str(), &end);

    if ((lim < -FLT_MAX || lim > std::numeric_limits<float>::max()) ||
        (end == str))
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
    char *end;
    float lim = std::strtod(str.c_str(), &end);
    
    if ((lim < -DBL_MAX ||
        lim > std::numeric_limits<double>::max()) || (end == str))
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

void            Utils::convertToChar(const std::string &str)
{
    if ((str[0] != '\'' && str[str.length() - 1] != '\'') && str[0] != '0')
    {
        std::cout << "int: " << static_cast<int>(str.at(0)) << std::endl;
        std::cout << "float: " << static_cast<float>(str.at(0)) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(str.at(0)) << ".0" << std::endl;
    }
    else if (str[0] == '0')
    {
        std::cout << "int: " << str << std::endl;
        std::cout << "float: " << str << ".0f" << std::endl;
        std::cout << "double: " << str << ".0" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(str.at(1)) << std::endl;
        std::cout << "float: " << static_cast<float>(str.at(1)) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(str.at(1)) << ".0" << std::endl;
    }
}