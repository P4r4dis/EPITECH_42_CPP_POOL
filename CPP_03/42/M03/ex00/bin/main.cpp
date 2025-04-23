/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:30:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/23 19:11:55 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int     main(void)
{
    ClapTrap    clapTrap("Clap");
    ClapTrap	clone = clapTrap;

    clapTrap.attack("BadBoy"); // 1st attack
    clapTrap.attack("BadBoy"); // 2nd attack
    clapTrap.attack("BadBoy"); // 3rd attack
    clapTrap.attack("BadBoy"); // 4th attack
    clapTrap.attack("BadBoy"); // 5th attack
    clapTrap.attack("BadBoy"); // 6th attack
    clapTrap.attack("BadBoy"); // 7th attack
    clapTrap.attack("BadBoy"); // 8th attack
    clapTrap.attack("BadBoy"); // 9th attack
    clapTrap.attack("BadBoy"); // 10th attack
    clapTrap.attack("BadBoy"); // out of energy
    clapTrap.takeDamage(9); // 1 hp left
    clapTrap.attack("BadBoy"); // out of energy
    clapTrap.takeDamage(1); // 0 hp left
    clapTrap.attack("BadBoy"); // already dead
    clone.attack("Friend of BadBoy"); // 1st attack
    clapTrap.beRepaired(10); // already dead

    return 0;
}