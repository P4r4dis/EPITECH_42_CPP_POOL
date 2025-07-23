/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:50:49 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:11:22 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScalarConverter.hpp"

int     main(int ac, char **av)
{
    if (ac == 1)
        std::cout   << "You need to add an argument like: " << std::endl
                    << "- A literal char: 'a' or 'b'..." << std::endl
                    << "- A literal int: 42 or 56..." << std::endl
                    << "- A literal float: 42.0f or 43.4f..." << std::endl
                    << "- A literal double: 4.2 or 6.5..." << std::endl;
    else
        ScalarConverter::convert(av[1]);
    return 0;
}