/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:26:55 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 16:00:59 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <iostream>
int     main(void)
{
    Serializer::Data *original = new Serializer::Data;
    original->_data = 42;

    uintptr_t raw = Serializer::serialize(original);

    Serializer::Data *result = Serializer::deserialize(raw);
    std::cout   << "addr of result pointer and original pointer "
                << "should be the same:" << std::endl
                << "addr result pointer: " << result << std::endl
                << "addr original pointer: " << original << std::endl;
    std::cout   << "value _data of result pointer and original pointer "
                << "should be the same:" << std::endl
                << "value _data of result pointer: " << result->_data 
                << std::endl
                << "value _data of original pointer: " << original->_data
                << std::endl;
    delete original;
    return 0;
}