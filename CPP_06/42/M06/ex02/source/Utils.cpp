/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:41:57 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 17:03:16 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <cstdlib>
#include <ctime>

Base    *generate(void)
{
    std::srand(std::time(0));

    unsigned int rand = std::rand() % 3;

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