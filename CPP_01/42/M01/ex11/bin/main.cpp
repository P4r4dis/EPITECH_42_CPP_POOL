/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/19 19:49:36 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2 )
        std::cerr   << "Error: level is unknown." << std::endl
                    << "Choose between: DEBUG, INFO, WARNING, ERROR."
                    << std::endl;
    else
    {
        Harl    harl;
        harl.dispatcher(av[1]);
    }
    return 0;
}