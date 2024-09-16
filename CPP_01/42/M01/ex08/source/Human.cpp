/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/16 19:50:48 by Paradis          ###   ########.fr       */
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

void        Human::intimidatingShout(std::string const & target)
{
    std::cout << "Human launches his intimidating shout on " << target << std::endl;
}

void        Human::action(std::string const & action_name, std::string const & target)
{
    void    (Human::*functionArray[])(std::string const & target) = { 
    &Human::meleeAttack,
    &Human::rangedAttack,
    &Human::intimidatingShout
    };

    std::string nameAction[] = { 
        "melee attack",
        "ranged attack", 
        "intimidating shout"
    };

    int     sizeArray = sizeof(nameAction) / sizeof(nameAction[0]);
    for (int i = 0; i < sizeArray; ++i)
        if (nameAction[i] == action_name)
        {
            (this->*functionArray[i])(target);
            return ;
        }

    std::cout << "Unknown action: " << action_name << std::endl;
}