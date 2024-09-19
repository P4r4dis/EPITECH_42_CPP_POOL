/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:58:27 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/19 20:15:42 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/MyCat.hpp"

int main(int ac, char **av)
{
    MyCat   myCat;
    if (ac < 2)
        myCat.usage();
    else
        for (int i = 1; i < ac; ++i)
            myCat.myCat(av[i]);
    return 0;
}