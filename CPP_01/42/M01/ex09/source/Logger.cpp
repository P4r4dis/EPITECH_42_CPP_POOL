/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 17:06:46 by Paradis          ###   ########.fr       */
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



