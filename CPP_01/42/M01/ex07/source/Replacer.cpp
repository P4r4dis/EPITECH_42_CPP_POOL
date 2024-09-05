/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/05 20:11:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Replacer.hpp"

Replacer::Replacer(std::string fileName, std::string s1, std::string s2)
                    :   _fileName(fileName), _s1(s1), _s2(s2)
{}

Replacer::~Replacer(void)
{}

std::ifstream       Replacer::openFile(std::string file)
{
    std::ifstream   inputStream;

    inputStream.open(file);
    if (!inputStream.is_open())
        std::cerr << "Error: Cannot open file <" << file << ">" << std::endl;
  
    return inputStream;
}



