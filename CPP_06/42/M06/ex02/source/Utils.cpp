/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:41:57 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 18:17:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base    *generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }


    unsigned int rand = std::rand() % 4;

    switch(rand)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return nullptr;
}

void    identify(Base *p)
{
    if (p)
    {
        if (dynamic_cast<A*>(p) != nullptr)
            std::cout << "Class A is identified." << std::endl;
        else if (dynamic_cast<B*>(p) != nullptr)
            std::cout << "Class B is identified." << std::endl;
        else if (dynamic_cast<C*>(p) != nullptr)
            std::cout << "Class C is identified." << std::endl;
    }
    else
        std::cout << "pointer is identified as nullptr." << std::endl;
}

void    identify(Base &p)
{
    std::cout << "By reference: ";
    if (dynamic_cast<A*>(&p) != nullptr)
        std::cout << "Class A is identified." << std::endl;
    else if (dynamic_cast<B*>(&p) != nullptr)
        std::cout << "Class B is identified." << std::endl;
    else if (dynamic_cast<C*>(&p) != nullptr)
        std::cout << "Class C is identified." << std::endl;
}