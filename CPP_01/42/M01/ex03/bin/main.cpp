/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 17:12:08 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Zombie.hpp"

int     main(void)
{
    std::cout   << "Creation of Zombie on the STACK:" << std::endl;
    Zombie  zombie0("Unknown 0");

    zombie0.announce();
    std::cout   << "name: " << zombie0.getName() << std::endl;
    std::cout   << "Set a real name:" << std::endl;
    zombie0.setName("Teddy");
    std::cout   << "name: " << zombie0.getName() << std::endl;

    std::cout   << "Creation of Zombie on the HEAP and use it out of the scope:" << std::endl;
    Zombie  *ptrZ = newZombie("Unknown 1");

    ptrZ->announce();
    std::cout   << "name: " << ptrZ->getName() << std::endl;
    std::cout   << "Set a real name:" << std::endl;
    ptrZ->setName("Murphy");
    std::cout   << "name: " << ptrZ->getName() << std::endl;
    std::cout   << "Destruction of Zombie on the HEAP and avoid MEMORY LEAK:" << std::endl;
    delete ptrZ;

    std::cout   << "Creation of random Zombie on the STACK:" << std::endl;
    randomChump("randomZ");

    std::cout   << "Creation of Zombie Horde on the HEAP:" << std::endl;
    Zombie  *ptrHorde = zombieHorde(5, "Unknown");

    for (int i = 0; i < 5; ++i)
        ptrHorde[i].announce();
    delete [] ptrHorde;
    return 0;
}