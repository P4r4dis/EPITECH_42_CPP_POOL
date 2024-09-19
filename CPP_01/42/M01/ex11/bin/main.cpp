/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/18 20:57:06 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>
int main(void)
{
    std::string debugLevel = "DEBUG";
    std::string infoLevel = "INFO";
    std::string warningLevel = "WARNING";
    std::string errorLevel = "ERROR";
    std::string somethingLevel = "SOMETHING";
    Harl        harl;

    std::cout << "DEUBG LEVEL: ";
    harl.complain(debugLevel);
    std::cout << "INFO LEVEL: ";
    harl.complain(infoLevel);
    std::cout << "WARNING LEVEL: ";
    harl.complain(warningLevel);
    std::cout << "ERROR LEVEL: ";
    harl.complain(errorLevel);
    std::cout << "ANYTHING LEVEL: ";
    harl.complain(somethingLevel);
    return 0;
}