/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:30:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/29 19:20:56 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int     main(void)
{
    ClapTrap	clap("Clap");
    ScavTrap	scav("Scav");

    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttack());
    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttack());
    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttack());
    scav.guardGate();
    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttack());
    scav.guardGate();

    return 0;
}