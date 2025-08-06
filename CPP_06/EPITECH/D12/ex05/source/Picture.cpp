/*
** Picture.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:38:04 PM 2025 Paradis
** Last update Thu Aug 6 8:38:06 PM 2025 Paradis
*/

#include "../include/Picture.hpp"

#include <fstream>
#include <string>

Picture::Picture(void)  :   _file("")
{
    this->data = "";
}

Picture::Picture(const std::string &file)   :   _file(file)
{
    getPictureFromFile(_file);
}

Picture::Picture(const Picture &picture)    :   data(picture.data),
                                                _file(picture._file)
{
}

Picture     &Picture::operator=(const Picture &picture)
{
    if (this != &picture)
    {
        data = picture.data;
        _file = picture._file;
    }
    return *this;
}

Picture::~Picture()
{
}

bool            Picture::getPictureFromFile(const std::string &file)
{
    std::fstream    fs;

    _file = file;
    fs.open(_file);
    
    if (fs.is_open())
    {
        while(std::getline(fs, data, '\0'))
            ;

        fs.close();
        return true;
    }
    
    data = "ERROR";
    return false;
}