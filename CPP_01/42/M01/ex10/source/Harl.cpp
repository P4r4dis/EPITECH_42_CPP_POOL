/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/18 18:44:35 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void            Harl::debug(void)
{
    std::cout   << "I love having extra bacon for my "
                << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
                << "I really do!" << std::endl;
}

void            Harl::info(void)
{
    std::cout   << "I cannot believe adding extra bacon costs more money. "
                << "You didn't put enough bacon in my burger! "
                << "If you did, I wouldn't be asking for more!" << std::endl;
}

void            Harl::warning(void)
{
    std::cout   << "I think I deserve to have some extra bacon for free. "
                << "I've been coming for years "
                << "whereas you started working here since last month."
                << std::endl;
}

void            Harl::error(void)
{
    return ;
}

void            Harl::complain(std::string level)
{
    void        (Harl::*functionArray[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levelArray[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int         sizeLevelArray = sizeof(levelArray) / sizeof(levelArray[0]);

    for (int i = 0; i < sizeLevelArray; ++i)
        if (levelArray[i] == level)
        {
            (this->*functionArray[i])();
            return ;
        }
    std::cerr   << "Error: level <" << level 
                << "> is unknown. Choose between DEBUG, INFO, WARNING, ERROR."
                << std::endl;
}