/*
** Picture.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 31 7:07:00 PM 2025 Paradis
** Last update Fri Jul 31 9:11:41 PM 2025 Paradis
*/

#include "../include/Picture.hpp"

#include <iostream>
#include <fstream>
#include <string>

Picture::Picture(void)  :   _file("")
{
    this->data = "ERROR";
}

Picture::~Picture()
{
}

bool            Picture::getPictureFromFile(const std::string &file)
{
    std::fstream    fs;

    _file = file;
    fs.open(_file);
    
    if (!fs.is_open())
    {
        if (_file.empty())
            data = "";
        std::cerr << data << std::endl;
        return false;
    }

    while(std::getline(fs, data, '\0'))
        ;

    fs.close();
    return true;
}