/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:49:54 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 16:59:33 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie      *zombieHorde(int N, std::string name)
{
    Zombie  *ptrZ = new Zombie[N];

    for (int i = 0; i < N; ++i)
        ptrZ[i].setName(name);
    
    return ptrZ;
}