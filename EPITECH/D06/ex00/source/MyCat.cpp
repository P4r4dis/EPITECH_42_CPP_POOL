#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <dirent.h>

#include "../include/MyCat.hpp"

MyCat::MyCat(void)
{}

MyCat::~MyCat(void)
{}

void            MyCat::usage(void)
{
    std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
}

bool            MyCat::isDirectory(std::string directory)
{
    DIR *dir;

    dir = opendir(directory.c_str());
    if (dir)
    {
        std::cerr << "my_cat: " << directory << ": Is a directory" << std::endl;
        closedir(dir);
        return true;
    }
    else
        return false;

}
void            MyCat::myCat(std::string fileName)
{
    std::fstream    fs;

    fs.open(fileName.c_str(), std::ios_base::in);

    if (!fs.is_open())
        std::cerr << "my_cat: " << fileName << ": " << std::strerror(errno) << std::endl;
    else if (isDirectory(fileName.c_str()))
        return ;
}