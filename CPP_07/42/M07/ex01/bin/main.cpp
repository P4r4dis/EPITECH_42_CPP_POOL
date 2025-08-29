/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:28:49 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/29 19:26:38 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/iter.hpp"

template <typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

int     main(void)
{

    int *array = NULL;
    iter(array, 0, print);

    int     array2[5] = {1, 2, 3, 4, 5};
    iter(array2, 0, print);

    int     array3[5] = {1, 2, 3, 4, 5};
    iter(array3, 5, print);

    char     array4[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(array4, 5, print);

    std::string     array6[6] = {"Hello", "World", "How", "Are", "You", "?"};
    iter(array6, 6, print);
    return 0;
}