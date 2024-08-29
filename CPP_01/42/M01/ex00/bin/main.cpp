/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 17:26:52 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Pony.hpp"

int     main(void)
{
    std::cout << "Create Pony on the STACK:" << std::endl;
    ponyOnTheStack("Goku");

    std::cout << "Create Pony on the HEAP:" << std::endl;
    ponyOnTheStack("Vegeta");
    
    return 0;
}