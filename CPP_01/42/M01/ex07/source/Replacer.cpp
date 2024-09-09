/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/09 17:47:41 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

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

std::string         Replacer::readFile(std::ifstream &inputStream)
{
    std::string     line;
    if (!inputStream.is_open())
        std::cerr << "Error: Cannot open file <" << _fileName << ">" << std::endl;
    
    if (!std::getline(inputStream, line, '\0'))
        std::cerr << "Error: Cannot read file <" << _fileName << ">" << std::endl;

    return line;
}

std::string         Replacer::replace(std::string line)
{
    if (!line.empty() && !_s1.empty() && !_s2.empty())
    {
        std::size_t pos = line.find(_s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, _s1.length());
            line.insert(pos, _s2);
            pos = line.find(_s1, ++pos);
        }
    }

    return line;
}

std::ofstream       Replacer::createFile(std::string path)
{
    std::ofstream   outputStream;
    if (!_fileName.empty())
    {
        std::string     tmpName = _fileName + ".replace";
        outputStream.open(path + tmpName);

        if (!outputStream)
            std::cerr << "Error open file <" << tmpName << ">" << std::endl;
        
        return outputStream;
    }
    else
    {
        std::cerr << "Error creating file <>" << std::endl;
        return outputStream;
    }
}

void       Replacer::writeFile(std::ofstream &outputStream)
{
    if (outputStream.is_open())
    {
        std::cout << _fileName << std::endl;
        std::ifstream   inputStream = openFile("42/M01/ex07/test/" + _fileName);
        std::string content = readFile(inputStream);
        content = replace(content);
        outputStream = createFile(_fileName);
        std::cout << content << std::endl;
        outputStream << content;
        return ;
    }
    else
    {
        std::cerr << "Error write in file <" << _fileName << ">" << std::endl;
        return ;   
    }
}