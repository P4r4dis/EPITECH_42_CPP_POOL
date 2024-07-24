#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include "../include/MyCat.hpp"

MyCat::MyCat(void)
{}

MyCat::~MyCat(void)
{}

void            MyCat::usage(void)
{
    std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
}

void            MyCat::myCat(std::string fileName)
{
    std::fstream    fs;

    fs.open(fileName, std::ios_base::in);
    if (!fs.is_open())
        std::cerr << "my_cat: " << fileName << ": " << std::strerror(errno) << std::endl;
}