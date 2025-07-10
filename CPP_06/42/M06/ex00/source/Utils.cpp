/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:37:18 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/10 20:50:01 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include <algorithm>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstddef>
#include <limits>
#include <string>

bool         Utils::isPseudoLiteral(const std::string &str)
{
    return  str == "+inff" || str == "-inff" || str == "+inf" || str == "-inf"
            || str == "nan" || str == "nanf";
}

bool         Utils::isChar(const std::string &str)
{
    if (str.length() != 1)
        return false;
    return true;
}

#include <iostream>
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