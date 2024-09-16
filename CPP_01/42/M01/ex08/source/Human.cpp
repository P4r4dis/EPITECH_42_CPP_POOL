/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/16 19:07:30 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "../include/Human.hpp"

void        Human::meleeAttack(std::string const & target)
{
    std::cout << "Human launches his melee attack on " << target << std::endl;
}

void        Human::rangedAttack(std::string const & target)
{
    std::cout << "Human launches his ranged attack on " << target << std::endl;
}