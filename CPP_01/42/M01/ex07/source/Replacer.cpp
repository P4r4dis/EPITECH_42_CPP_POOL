/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/11 18:23:39 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/Replacer.hpp"

Replacer::Replacer(std::string fileName, std::string s1, std::string s2)
                                                :   _fileName(fileName),
                                                    _s1(s1),
                                                    _s2(s2)
{}

Replacer::~Replacer(void)
{}

void            Replacer::sed(void)
{
    std::ifstream   ifs(_fileName.c_str());
    std::string     newFileName = (_fileName + ".replace").c_str();
    
    if (!ifs.is_open())
        std::cerr << "Error: File <" << _fileName.c_str() << "> is not open." << std::endl;
    else
    {
        std::string line;
        if (std::getline(ifs, line, '\0'))
        {
            size_t pos = line.find(_s1);
            while (pos != std::string::npos)
            {
                line.erase(pos, _s1.size());   // Supprimer _s1 à la position trouvée
                line.insert(pos, _s2);           // Insérer _s2 à la même position
                pos = line.find(_s1, pos + _s2.size());
            }
            std::ofstream   ofs(newFileName.c_str());
            if (!ofs.is_open())
                std::cerr << "Error: File <" << newFileName << "> is not open." << std::endl;
            ofs << line;
            ofs.close();
        }
    }
    ifs.close();
}