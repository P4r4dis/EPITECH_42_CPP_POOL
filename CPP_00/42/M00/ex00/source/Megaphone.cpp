/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:11:25 by Paradis           #+#    #+#             */
/*   Updated: 2024/06/25 18:12:07 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Megaphone.hpp"

Megaphone::Megaphone(int ac, char **av) : _ac(ac), _av(av)
{
    if (_ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < _ac ; i++)
            for (int j = 0; _av[i][j] != '\0'; j++)
            {
                _av[i][j] = std::toupper(_av[i][j]);
                std::cout << _av[i][j];
            }
    std::cout << std::endl;
}

Megaphone::~Megaphone(void)
{}
