/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 19:46:04 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ctime> 
#include <sstream>
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

std::ofstream           &Logger::getFileStream(void)
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
        std::cerr   << "Error: File <" << _fileName 
                    << "> is not open." << std::endl;
    else
        _fileStream << msg << std::endl;
}

std::string             Logger::makeLogEntry(std::string msg)
{
    std::ostringstream oss;
    std::time_t t = std::time(nullptr);
    std::string result = std::asctime(std::localtime(&t));
    
    result.erase(result.length() - 1);
    oss << "[" + result + "]: " << msg;
    return oss.str();
}
void                    Logger::log(const std::string & dest,
                                    const std::string & message)
{
    std::string     arrayDest[] = { "Console", "File" };
    int             sizeArrayDest = sizeof(arrayDest) / sizeof(arrayDest[0]);
    void            (Logger::*functionArray[])(std::string message) = 
                    { &Logger::logToConsole, &Logger::logToFile };

    for (int i = 0; i < sizeArrayDest; ++i)
        if ( arrayDest[i] == dest)
        {
            (this->*functionArray[i])(makeLogEntry(message));
            return ;
        }

    std::cerr   << "Error: Destination " << dest 
                << " is unknown. Choose between <Console> and <File>." 
                << std::endl;
}