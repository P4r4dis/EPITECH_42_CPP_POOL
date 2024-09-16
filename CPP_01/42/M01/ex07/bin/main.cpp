/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/11 19:35:32 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Replacer.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout   << "Error: you need 3 arguments"
                    << " -> <filename> <strToFind> <strToReplace>"
                    << std::endl;
        return 1;
    }
    else
    {
        Replacer    replacer(av[1], av[2], av[3]);
        replacer.sed();
    }
    return 0;
}