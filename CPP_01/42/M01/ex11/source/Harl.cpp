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
    std::cout   << "[ DEBUG ]" << std::endl
                << "I love having extra bacon for my "
                << "7XL-double-cheese-triple-pickle-special-ketchup burger."
                << std::endl
                << "I really do!" << std::endl;
}

void            Harl::info(void)
{
    std::cout   << "[ INFO ]" << std::endl
                << "I cannot believe adding extra bacon costs more money."
                << std::endl
                << "You didn't put enough bacon in my burger!" << std::endl
                << "If you did, I wouldn't be asking for more!" << std::endl;
}

void            Harl::warning(void)
{
    std::cout   << "[ WARNING ]" << std::endl
                << "I think I deserve to have some extra bacon for free."
                << std::endl
                << "I've been coming for years "
                << "whereas you started working here since last month."
                << std::endl;
}

void            Harl::error(void)
{
    std::cout   << "[ ERROR ]" << std::endl
                << "This is unacceptable, I want to speak to the manager now."
                << std::endl;
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
                << "> is unknown. Choose between: DEBUG, INFO, WARNING, ERROR."
                << std::endl;
}

void            Harl::dispatcher(std::string level)
{
    void        (Harl::*functionArray[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levelArray[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int         sizeLevelArray = sizeof(levelArray) / sizeof(levelArray[0]);
    int         filter = -1;

    for (int i = 0; i < sizeLevelArray; ++i)
        if (levelArray[i] == level)
            filter = i;

    for (; filter < sizeLevelArray; ++filter)
    {
        switch (filter)
        {
            case 0:
                (this->*functionArray[filter])();
                break;
            case 1:
                (this->*functionArray[filter])();
                break;
            case 2:
                (this->*functionArray[filter])();
                break;
            case 3:
                (this->*functionArray[filter])();
                break;
            default:
                std::cerr   <<  "[ "
                            << "Probably complaining " 
                            << "about insignificant problems ]" << std::endl;
                return;
        }
        std::cout << std::endl;
    }
}