/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:30:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/29 20:04:11 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int     main(void)
{
    FragTrap fragTrap("Frag");

    fragTrap.attack("BadBoy");
    fragTrap.takeDamage(50);
    fragTrap.beRepaired(1);
    fragTrap.highFivesGuy();
    return 0;
}