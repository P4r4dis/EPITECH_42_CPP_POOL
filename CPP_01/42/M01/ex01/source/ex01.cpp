/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:51:47 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 18:53:38 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/ex01.hpp"

void    memoryLeak(void)
{
    std::string* panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;

    delete panthere;
}