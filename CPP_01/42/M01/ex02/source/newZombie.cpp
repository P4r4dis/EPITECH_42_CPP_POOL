/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:02:00 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/30 16:12:53 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Allocates on the Heap for be allowed to use Zombie outside of the scope.
Zombie      *newZombie(std::string name)
{
    return new Zombie(name);
}