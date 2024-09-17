/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 17:37:10 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <iostream>
#include <string>

#include "../include/Logger.hpp"

Logger::Logger(std::string fileName)    :   _fileName(fileName),
                                            _fileStream(_fileName,
                                            std::ios::in | std::ios::app)
{}

Logger::~Logger(void)
{
    if (_fileStream.is_open())
        _fileStream.close();
}

std::string             Logger::getFileName(void) const
{
    return _fileName;
}

const std::ofstream     &Logger::getFileStream(void) const
{
    return _fileStream;
}

void                    Logger::logToConsole(std::string msg)
{
    std::cout << msg << std::endl;
}

void                    Logger::logToFile(std::string msg)
{
    if (!_fileStream.is_open())
        std::cout   << "Error: file <" << _fileName 
                    << "> is not open." << std::endl;
    else
        _fileStream << msg;
}
