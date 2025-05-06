/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:24:04 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/06 17:16:05 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int     main(void)
{
    DiamondTrap    diamondTrap("DiamondTrap");

    diamondTrap.attack("BadBoy");
    diamondTrap.takeDamage(50);
    diamondTrap.beRepaired(1);
    diamondTrap.whoAmI();
    
    return 0;
}